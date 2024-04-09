/*
    Kyle Plant
    2024-04-06
    Dual input frequency measurement and directional logic for inductive loop system
    with LoRaWAN TTN network connectivity

    Add ability to manually set delta with LoRaWAN (downlink from gateway)
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "esp_event.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_timer.h"
#include "driver/pulse_cnt.h"
#include "esp_system.h"
#include "esp_err.h"
#include "esp_task_wdt.h"
#include "nvs_flash.h"
#include "nvs.h"

#include "ttn.h"


#define TWDT_TIMEOUT_MS 5000 // task watchdog timeout
static esp_task_wdt_user_handle_t pcnt_task_twdt_user_hdl;
static esp_task_wdt_user_handle_t dir_logic_task_twdt_user_hdl;

#define PCNT_INPUT_PIN_1 34
#define PCNT_INPUT_PIN_2 35
#define NUM_FREQ_VALS 3

// Determines values that cause PCNT to overflow, max values are chosen
#define EXAMPLE_PCNT_HIGH_LIMIT 32767
#define EXAMPLE_PCNT_LOW_LIMIT  -32768

// How much of a frequency change is needed for it to be counted as a vehicle
#define LOOP_DETECTION_THRESHOLD_HZ 150 

#define SAMPLE_WINDOW_MS 350

// The amount of time it takes for an event to become "stale"
// meaning, if there is a singular event with no event on the
// opposite loop within this timeframe, that singular event
// will be thrown out
#define TIME_TO_STALE_EVENT_MS 2000

// Delta cannot be changed again until this amount of time since last change
#define DELTA_TIMEOUT_MS 250

// This is how you choose which loop is considered the entrance and exit loop
#define LOOP_A_FIRST 1

int freq_array_index = 0;
float freq_avg_loop_a = 0;
float freq_avg_loop_b = 0;

// Delta value which will be kept in nonvolatile storage
// Current delta is set to zero if it does not already exist, 
// this is done in read_current_delta_from_nvs()
#define NVS_NAMESPACE "storage"
#define NVS_KEY_CURRENT_DELTA "current_delta"
int32_t current_delta;

float freq_array_loop_a[NUM_FREQ_VALS] = {[0 ... (NUM_FREQ_VALS-1)] = 0};
float freq_array_loop_b[NUM_FREQ_VALS] = {[0 ... (NUM_FREQ_VALS-1)] = 0};

typedef enum {LOOP_A, LOOP_B, INVALID} LOOP_ID;

// Loop Event struct
typedef struct  
{
    int64_t timestamp;
    float frequency;
    LOOP_ID loop_id;
} Loop_Event;

#define QUEUE_LENGTH 15
QueueHandle_t loop_event_queue;

TaskHandle_t pcnt_task_handle;
TaskHandle_t dir_logic_task_handle;
TaskHandle_t sendMessages_task_handle;

pcnt_unit_config_t unit_config = {
        .high_limit = EXAMPLE_PCNT_HIGH_LIMIT,
        .low_limit = EXAMPLE_PCNT_LOW_LIMIT,
    };
pcnt_unit_handle_t pcnt_unit_0 = NULL;
pcnt_unit_handle_t pcnt_unit_1 = NULL;

pcnt_chan_config_t chan_config_0 = {
    .edge_gpio_num = PCNT_INPUT_PIN_1,
};
pcnt_channel_handle_t pcnt_0_chan = NULL;

pcnt_chan_config_t chan_config_1 = {
    .edge_gpio_num = PCNT_INPUT_PIN_2,
};
pcnt_channel_handle_t pcnt_1_chan = NULL;

// NOTE:
// The LoRaWAN frequency and the radio chip must be configured by running 'idf.py menuconfig'.
// Go to Components / The Things Network, select the appropriate values and save.

// Copy the below hex strings from the TTN console (Applications > Your application > End devices
// > Your device > Activation information)

// AppEUI (sometimes called JoinEUI)
const char *appEui = "1AB602AC9EF112BF";
// DevEUI
const char *devEui = "70B3D57ED80029D0";
// AppKey
const char *appKey = "F64422CFA825B4D89FF6B074027B41C5";

// Pins and other resources
#define TTN_SPI_HOST      SPI2_HOST
#define TTN_SPI_DMA_CHAN  SPI_DMA_DISABLED
#define TTN_PIN_SPI_SCLK  18
#define TTN_PIN_SPI_MOSI  23
#define TTN_PIN_SPI_MISO  19
#define TTN_PIN_NSS       5
#define TTN_PIN_RXTX      TTN_NOT_CONNECTED
#define TTN_PIN_RST       14
#define TTN_PIN_DIO0      2
#define TTN_PIN_DIO1      16

// For debugging purposes, choose 0 to not have any LoRaWAN connectivity
// choose 1 to use LoRaWAN network
#define DO_LORAWAN 1


// Nonvolatile Storage

void initialize_nvs() {
    // Initialize NVS
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
}

void read_current_delta_from_nvs() {
    // Open NVS
    nvs_handle_t nvs_handle;
    ESP_ERROR_CHECK(nvs_open(NVS_NAMESPACE, NVS_READWRITE, &nvs_handle));

    // Read current_delta from NVS
    esp_err_t ret = nvs_get_i32(nvs_handle, NVS_KEY_CURRENT_DELTA, &current_delta);
    if (ret == ESP_ERR_NVS_NOT_FOUND) {
        // Value not found, set default
        current_delta = 0;
    } else {
        ESP_ERROR_CHECK(ret);
    }

    // Close NVS
    nvs_close(nvs_handle);
}

void write_current_delta_to_nvs() {
    // Open NVS
    nvs_handle_t nvs_handle;
    ESP_ERROR_CHECK(nvs_open(NVS_NAMESPACE, NVS_READWRITE, &nvs_handle));

    // Write current_delta to NVS
    ESP_ERROR_CHECK(nvs_set_i32(nvs_handle, NVS_KEY_CURRENT_DELTA, current_delta));

    // Commit changes
    ESP_ERROR_CHECK(nvs_commit(nvs_handle));

    // Close NVS
    nvs_close(nvs_handle);
}

#define TX_INTERVAL 30 // time interval to send messages in seconds
//static uint8_t msgData[] = "Hello, world"; // Test message


// LoRa functions

void sendMessages(void* pvParameter)
{
    while (1) {
        // Read current_delta from NVS
        read_current_delta_from_nvs();

        // Convert current_delta to byte array
        uint8_t deltaBytes[sizeof(int32_t)];
        memcpy(deltaBytes, &current_delta, sizeof(int32_t));

        // Send current_delta over LoRa
        printf("Sending message...\n");
        ttn_response_code_t res = ttn_transmit_message(deltaBytes, sizeof(deltaBytes), 1, false);
        printf(res == TTN_SUCCESSFUL_TRANSMISSION ? "Message sent.\n" : "Transmission failed.\n");

        vTaskDelay(TX_INTERVAL * pdMS_TO_TICKS(1000));
    }
}


void messageReceived(const uint8_t* message, size_t length, ttn_port_t port)
{
    printf("Message of %d bytes received on port %d:", length, port);
    for (int i = 0; i < length; i++)
        printf(" %02x", message[i]);
    printf("\n");
}


// Initial frequency tuning function
void initial_freq_tune()
{   
    int64_t curr_time_us = 0;
    int64_t prev_time_us = 0;
    int64_t elapsed_time_us = 0;
    int pulse_count = 0;
    float frequency = 0;


    printf("\n\nTUNING LOOP A");
    for(int i = 0; i < NUM_FREQ_VALS; i++)
    {
        // Loop A
        curr_time_us = esp_timer_get_time();

        ESP_ERROR_CHECK(pcnt_unit_get_count(pcnt_unit_0, &pulse_count));
        printf("\npulse count 1: %d", pulse_count);

        elapsed_time_us = curr_time_us - prev_time_us;

        frequency = (float)pulse_count / (elapsed_time_us / 1e6);
        printf("\nfrequency 1: %f Hz", frequency);
        prev_time_us = curr_time_us;

        freq_array_loop_a[i] = frequency;

        pcnt_unit_clear_count(pcnt_unit_0);

        vTaskDelay(pdMS_TO_TICKS(SAMPLE_WINDOW_MS));
    }

    // First PCNT value is off by a lot, replace it with the most recent value
    freq_array_loop_a[0] = freq_array_loop_a[NUM_FREQ_VALS-1];

    curr_time_us = 0;
    prev_time_us = 0;
    elapsed_time_us = 0;
    pulse_count = 0;
    frequency = 0;

    printf("\n\nTUNING LOOP B");
    for(int i = 0; i < NUM_FREQ_VALS; i++)
    {
        // Loop B
        curr_time_us = esp_timer_get_time();

        ESP_ERROR_CHECK(pcnt_unit_get_count(pcnt_unit_1, &pulse_count));
        printf("\npulse count 1: %d", pulse_count);

        elapsed_time_us = curr_time_us - prev_time_us;

        frequency = (float)pulse_count / (elapsed_time_us / 1e6);
        printf("\nfrequency 1: %f Hz", frequency);
        prev_time_us = curr_time_us;

        freq_array_loop_b[i] = frequency;

        pcnt_unit_clear_count(pcnt_unit_1);

        vTaskDelay(pdMS_TO_TICKS(SAMPLE_WINDOW_MS));
    }

    // First PCNT value is off by a lot, replace it with the most recent value
    freq_array_loop_b[0] = freq_array_loop_b[NUM_FREQ_VALS-1];

    float sum_a = 0; 
    float sum_b = 0;
    for (int i = 0; i < NUM_FREQ_VALS; i++)
    {
        sum_a += freq_array_loop_a[i];
        sum_b += freq_array_loop_b[i];
    }
    freq_avg_loop_a = sum_a / NUM_FREQ_VALS;
    freq_avg_loop_b = sum_b / NUM_FREQ_VALS;

    printf("\n\n\nTuning finished!\nLoop A: Average Frequency is %f", freq_avg_loop_a);
    printf("\nLoop B: Average Frequency is %f", freq_avg_loop_b);
}


//FreeRTOS tasks

// Pulse Counter task: counts pulses per timeframe, gets frequency, 
// sends changes in frequency exceeding threshold to event queues
void pcnt_task(void *arg)
{
    int pulse_count_loop_a = 0;
    int pulse_count_loop_b = 0;
    int64_t curr_time_us_0 = 0;
    int64_t curr_time_us_1 = 0;
    int64_t prev_time_us_0 = 0;
    int64_t prev_time_us_1 = 0;
    int64_t elapsed_time_us_0 = 0;
    int64_t elapsed_time_us_1 = 0;
    float freq_loop_a = 0;
    float freq_loop_b = 0;

    // Subscribe this task to TWDT, then check if it is subscribed
    ESP_ERROR_CHECK(esp_task_wdt_add(NULL));
    ESP_ERROR_CHECK(esp_task_wdt_status(NULL));

    // Subscribe func_a and func_b as users of the the TWDT
    ESP_ERROR_CHECK(esp_task_wdt_add_user("pcnt", &pcnt_task_twdt_user_hdl));
    esp_task_wdt_reset_user(pcnt_task_twdt_user_hdl);

    printf("\npcnt subscribed to TWDT\n");

    pcnt_unit_clear_count(pcnt_unit_0);
    prev_time_us_0 = esp_timer_get_time();

    pcnt_unit_clear_count(pcnt_unit_1);
    prev_time_us_1 = esp_timer_get_time();

    vTaskDelay(pdMS_TO_TICKS(SAMPLE_WINDOW_MS));

    while(1)
    {
        // Freq 1

        // Get current time for freq1
        curr_time_us_0 = esp_timer_get_time();

        ESP_ERROR_CHECK(pcnt_unit_get_count(pcnt_unit_0, &pulse_count_loop_a));

        elapsed_time_us_0 = curr_time_us_0 - prev_time_us_0;

        freq_loop_a = (float)pulse_count_loop_a / (elapsed_time_us_0 / 1e6);
        prev_time_us_0 = curr_time_us_0;

        // Clear PCNT unit 0
        pcnt_unit_clear_count(pcnt_unit_0);

        //printf("\n\n\npulse count 1: %d", pulse_count_loop_a);
        //printf("\nfrequency 1: %f Hz", freq_loop_a);


        // Freq 2
        curr_time_us_1 = esp_timer_get_time();

        ESP_ERROR_CHECK(pcnt_unit_get_count(pcnt_unit_1, &pulse_count_loop_b));

        elapsed_time_us_1 = curr_time_us_1 - prev_time_us_1;

        freq_loop_b = (float)pulse_count_loop_b / (elapsed_time_us_1 / 1e6);
        prev_time_us_1 = curr_time_us_1;

        // Clear PCNT unit 1
        pcnt_unit_clear_count(pcnt_unit_1);

        //printf("\npulse count 2: %d", pulse_count_loop_b);
        //printf("\nfrequency 2: %f Hz", freq_loop_b);


        // Check if frequency is abnormal, push to queue if so
        if((freq_loop_a - freq_avg_loop_a) > LOOP_DETECTION_THRESHOLD_HZ)
        {
            printf("\nLOOP_A: DEVIATION IN FREQ DETECTED!");
            Loop_Event loop_evt;
            loop_evt.timestamp = curr_time_us_0;
            loop_evt.frequency = freq_loop_a;
            loop_evt.loop_id = LOOP_A;
            xQueueSend(loop_event_queue, &loop_evt, pdMS_TO_TICKS(10));
        }
        
        if((freq_loop_b - freq_avg_loop_b) > LOOP_DETECTION_THRESHOLD_HZ)
        {
            printf("\nLOOP_B: DEVIATION IN FREQ DETECTED!");
            Loop_Event loop_evt;
            loop_evt.timestamp = curr_time_us_1;
            loop_evt.frequency = freq_loop_b;
            loop_evt.loop_id = LOOP_B;
            xQueueSend(loop_event_queue, &loop_evt, pdMS_TO_TICKS(10));
        }

        // Add to the freq arrays
        freq_array_loop_a[freq_array_index] = freq_loop_a;
        freq_array_loop_b[freq_array_index] = freq_loop_b;
        freq_array_index = (freq_array_index+1) % NUM_FREQ_VALS;

        // Get array averages
        float sum_a = 0;
        float sum_b = 0;
        for (int i = 0; i < NUM_FREQ_VALS; i++)
        {
            sum_a += freq_array_loop_a[i];
            sum_b += freq_array_loop_b[i];
        }
        freq_avg_loop_a = sum_a / NUM_FREQ_VALS;
        freq_avg_loop_b = sum_b / NUM_FREQ_VALS;

        //printf("\n\nLoop A avg: %f", freq_avg_loop_a);
        //printf("\nLoop B avg: %f", freq_avg_loop_b);

        esp_task_wdt_reset();
        esp_task_wdt_reset_user(pcnt_task_twdt_user_hdl);
        vTaskDelay(pdMS_TO_TICKS(SAMPLE_WINDOW_MS));
    }
    // Unsubscribe this task, func_a, and func_b
    ESP_ERROR_CHECK(esp_task_wdt_delete_user(pcnt_task_twdt_user_hdl));
    ESP_ERROR_CHECK(esp_task_wdt_delete(NULL));

    printf("\nUnsubscribed from TWDT\n");

    // Notify main task of deletion
    xTaskNotifyGive((TaskHandle_t)arg);
    vTaskDelete(NULL);
}

// Directional Logic task: 
// Check for events, analyze them: 
// Identify valid detection events and get directionality
// Leave singular events that are recent, another may arrive soon
// Discard stale events, events that are a certain age
void dir_logic_task(void *arg)
{
    // Subscribe this task to TWDT, then check if it is subscribed
    ESP_ERROR_CHECK(esp_task_wdt_add(NULL));
    ESP_ERROR_CHECK(esp_task_wdt_status(NULL));

    // Subscribe func_a and func_b as users of the the TWDT
    ESP_ERROR_CHECK(esp_task_wdt_add_user("dir_logic", &dir_logic_task_twdt_user_hdl));

    printf("\ndir_logic subscribed to TWDT\n");

    // Last time delta was changed
    int64_t last_delta_change_time = 0;

    // value of last event timestamp
    int64_t last_event_timestamp = 0;

    static LOOP_ID last_event_id = INVALID;

    while(1)
    {
        //printf("\n\nDelta %ld", current_delta);
        // Instance of loop event
        Loop_Event loop_evt;

        //printf("\nlast_event_id at beginning: %d", last_event_id);

        if(xQueueReceive(loop_event_queue, &loop_evt, pdMS_TO_TICKS(10)) == pdTRUE)
        {
            // Check if the last two events were on different loops
            // and also if they were close enough together to be related

            //printf("\nReceived from queue loop_id: %d", loop_evt.loop_id);
            // Get the current time in microseconds
            int64_t curr_time_us = esp_timer_get_time();

            //int64_t diff;
            //diff = curr_time_us - last_event_timestamp;
            //printf("\ncurr time: %lld, event timestamp: %lld, diff: %lld", curr_time_us, last_event_timestamp, diff);

            if((loop_evt.loop_id != last_event_id) && ((curr_time_us - last_event_timestamp) < (TIME_TO_STALE_EVENT_MS*1000)))
            {
                printf("\n\nEvents with different ID detected!");

                if((last_event_id == LOOP_A) && (loop_evt.loop_id == LOOP_B) && ((curr_time_us - last_delta_change_time) > DELTA_TIMEOUT_MS*1000)) // Loop A then B triggered
                {
                    printf("\nLoop A then Loop B");
                    if(LOOP_A_FIRST)
                    {
                        read_current_delta_from_nvs();
                        current_delta++;
                        printf("\n\nDelta increased to %ld", current_delta);
                        write_current_delta_to_nvs();
                        last_delta_change_time = esp_timer_get_time();
                    }
                    else
                    {
                        read_current_delta_from_nvs();
                        current_delta--;
                        printf("\n\nDelta decreased to %ld", current_delta);
                        write_current_delta_to_nvs();
                        last_delta_change_time = esp_timer_get_time();
                    }
                }
                else if((last_event_id == LOOP_B) && (loop_evt.loop_id == LOOP_A) && (curr_time_us - last_delta_change_time > DELTA_TIMEOUT_MS*1000)) // Loop B then A triggered
                {
                    printf("\nLoop B then Loop A");
                    if(LOOP_A_FIRST)
                    {
                        read_current_delta_from_nvs();
                        current_delta--;
                        printf("\n\nDelta decreased to %ld", current_delta);
                        write_current_delta_to_nvs();
                        last_delta_change_time = esp_timer_get_time();
                    }
                    else
                    {
                        read_current_delta_from_nvs();
                        current_delta++;
                        printf("\n\nDelta increased to %ld", current_delta);
                        write_current_delta_to_nvs();
                        last_delta_change_time = esp_timer_get_time();
                    }
                }
                else
                {
                    last_event_id = loop_evt.loop_id;
                    continue;
                }
            }
            last_event_timestamp = loop_evt.timestamp;
            last_event_id = loop_evt.loop_id;
            //printf("\nlast_event_id at end: %d", last_event_id);
        }
        esp_task_wdt_reset();
        esp_task_wdt_reset_user(dir_logic_task_twdt_user_hdl);
        vTaskDelay(pdMS_TO_TICKS(70));
    }
    // Unsubscribe this task, func_a, and func_b
    ESP_ERROR_CHECK(esp_task_wdt_delete_user(dir_logic_task_twdt_user_hdl));
    ESP_ERROR_CHECK(esp_task_wdt_delete(NULL));

    printf("\ndir_logic unsubscribed from TWDT\n");

    // Notify main task of deletion
    xTaskNotifyGive((TaskHandle_t)arg);
    vTaskDelete(NULL);
}

void app_main(void)
{
    loop_event_queue = xQueueCreate(QUEUE_LENGTH, sizeof(Loop_Event));

    // Configure PCNT units

    ESP_ERROR_CHECK(pcnt_new_unit(&unit_config, &pcnt_unit_0));
    ESP_ERROR_CHECK(pcnt_new_unit(&unit_config, &pcnt_unit_1));

    ESP_ERROR_CHECK(pcnt_new_channel(pcnt_unit_0, &chan_config_0, &pcnt_0_chan));
    ESP_ERROR_CHECK(pcnt_channel_set_edge_action(pcnt_0_chan, PCNT_CHANNEL_EDGE_ACTION_INCREASE, PCNT_CHANNEL_EDGE_ACTION_HOLD));

    ESP_ERROR_CHECK(pcnt_new_channel(pcnt_unit_1, &chan_config_1, &pcnt_1_chan));
    ESP_ERROR_CHECK(pcnt_channel_set_edge_action(pcnt_1_chan, PCNT_CHANNEL_EDGE_ACTION_INCREASE, PCNT_CHANNEL_EDGE_ACTION_HOLD));

    // Enable and ready PCNT units
    pcnt_unit_enable(pcnt_unit_0);
    pcnt_unit_start(pcnt_unit_0);
    pcnt_unit_clear_count(pcnt_unit_0);

    pcnt_unit_enable(pcnt_unit_1);
    pcnt_unit_start(pcnt_unit_1);
    pcnt_unit_clear_count(pcnt_unit_1);

    #if !CONFIG_ESP_TASK_WDT_INIT
    // If the TWDT was not initialized automatically on startup, manually intialize it now
    esp_task_wdt_config_t twdt_config = {
        .timeout_ms = TWDT_TIMEOUT_MS,
        .idle_core_mask = (1 << CONFIG_FREERTOS_NUMBER_OF_CORES) - 1,    // Bitmask of all cores
        .trigger_panic = false,
    };
    ESP_ERROR_CHECK(esp_task_wdt_init(&twdt_config));
    printf("\nTWDT initialized\n");
    #endif // CONFIG_ESP_TASK_WDT_INIT

    initialize_nvs();
    read_current_delta_from_nvs();

    if(DO_LORAWAN)
    {
        esp_err_t err;
        // Initialize the GPIO ISR handler service
        err = gpio_install_isr_service(ESP_INTR_FLAG_IRAM);
        ESP_ERROR_CHECK(err);

        // Initialize SPI bus
        spi_bus_config_t spi_bus_config = {
            .miso_io_num = TTN_PIN_SPI_MISO,
            .mosi_io_num = TTN_PIN_SPI_MOSI,
            .sclk_io_num = TTN_PIN_SPI_SCLK,
            .quadwp_io_num = -1,
            .quadhd_io_num = -1
        }; 
        err = spi_bus_initialize(TTN_SPI_HOST, &spi_bus_config, TTN_SPI_DMA_CHAN);
        ESP_ERROR_CHECK(err);

        // Initialize TTN
        ttn_init();

        // Configure the SX127x pins
        ttn_configure_pins(TTN_SPI_HOST, TTN_PIN_NSS, TTN_PIN_RXTX, TTN_PIN_RST, TTN_PIN_DIO0, TTN_PIN_DIO1);

        // The below line can be commented after the first run as the data is saved in NVS
        //ttn_provision(devEui, appEui, appKey);

        // Register callback for received messages
        ttn_on_message(messageReceived);

        ttn_set_adr_enabled(false);
        ttn_set_data_rate(TTN_DR_US915_SF10);
        ttn_set_max_tx_pow(20);

        printf("Joining...\n");
        if (ttn_join())
        {
            printf("Joined.\n");
            xTaskCreatePinnedToCore(sendMessages, "send_messages", 4096, NULL, 10, &sendMessages_task_handle, 1);
        }
        else
        {
            printf("Join failed. Goodbye\n");
        }
    }

    initial_freq_tune();

    // Create and start the pcnt tasks
    xTaskCreatePinnedToCore(pcnt_task, "pcnt_task", 4096, NULL, 10, &pcnt_task_handle, 0);
    xTaskCreatePinnedToCore(dir_logic_task, "dir_logic_task", 4096, NULL, 10, &dir_logic_task_handle, 0);
}
