#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cmath>
#include <vector>
#include <ctime>
#include <pigpio.h>
#include <thread>
#include <chrono>

using namespace std;

const int PWM_PIN1 = 18;  // BCM GPIO 18, which supports hardware PWM on Raspberry Pi

void generateSquareWave(double pulseWidthMs, double dutyCycle) {
    
    int frequency = 1000 / pulseWidthMs;
    int dutyCycleScaled = static_cast<int>(dutyCycle * 10000); // Scale from 0 to 1,000,000

    int result = gpioHardwarePWM(PWM_PIN1, frequency, dutyCycleScaled);
    if (result != 0) {
        std::cerr << "Failed to set PWM!" << std::endl;
        gpioTerminate();
        return;
    }
}

int main() {
    // Initialize pigpio
    if (gpioInitialise() < 0) {
        cerr << "pigpio initialization failed!" << endl;
        return 1;
    }

    double dutyCycle = 0;
    //int i = 0;

    // Set the pin mode to output
    gpioSetMode(PWM_PIN1, PI_OUTPUT);

    while(1){
        // Ask for the duty cycle (in percentage)
        //double dutyCycle;
        cout << "Enter duty cycle in percentage (0-100): ";
        cin >> dutyCycle;
        //for(i = 10;i < 90;i = i + 5){
            //dutyCycle = i;
            //cerr << i << endl;
            //sleep(1);

            if (dutyCycle < 0 || dutyCycle > 100) {
            cerr << "Duty cycle must be between 0 and 100." << endl;
            gpioTerminate();
            return 1;
            }

            // Generate the square wave with the given pulse width and duty cycle
            cout << "Generating square wave on GPIO pin " << PWM_PIN1 
                << " with pulse width " << 2.5 << " ms and duty cycle " 
                << dutyCycle << "%" << endl;

            generateSquareWave(2.5, dutyCycle);
        //}

        
    }

    gpioTerminate();  // Clean up pigpio resources (though this line will not be reached)
    return 0;
}
