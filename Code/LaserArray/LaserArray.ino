
 byte Line = 0; //initalize global varaiable to which line is tripped
 char Test = 0;
char mask = 0;
 char mask1 = 0;
 char* BUG;
void setup() {
  
  //This enables 15 pinchange interupt functions
  PCICR |= (1 << PCIE0);
  PCICR |= (1 << PCIE2);

  //All pins that for pinchange interupt 0
  PCMSK0 |= (1 << PCINT0);//pin 53 - B0 
  PCMSK0 |= (1 << PCINT1);//pin 52 - B1 
  PCMSK0 |= (1 << PCINT2);//pin 51 - B2 
  PCMSK0 |= (1 << PCINT3);//pin 50 - B3 
  PCMSK0 |= (1 << PCINT4);//pin 10 - B4 
  PCMSK0 |= (1 << PCINT5);//pin 11 - B5 
  PCMSK0 |= (1 << PCINT6);//pin 12 - B6 
  PCMSK0 |= (1 << PCINT7);//pin 13 - B7 

  //7 pins for pinchange interupt 1
  PCMSK2 |= (1 << PCINT16);//pin 15 - J0 - Rx Channel 10
  PCMSK2 |= (1 << PCINT17);//pin 14 - J1 - Rx Channel 11
  PCMSK2 |= (1 << PCINT18);//pin 22 - J6 - Rx Channel 12
  PCMSK2 |= (1 << PCINT19);//pin 24 - J5 - Rx Channel 13
  PCMSK2 |= (1 << PCINT20);//pin 26 - J4 - Rx Channel 14
  PCMSK2 |= (1 << PCINT21);//pin 28 - J3 - Rx Channel 15
  PCMSK2 |= (1 << PCINT22);//pin 30 - J2 - Rx Channel 16
  PCMSK2 |= (1 << PCINT23);//pin 30 - J2 - Rx Channel 16

 // DDRB = 0b00000000;
//  DDRJ = 0b00000000;
  DDRE = 0b11111111;

  PORTE = 0b00000000;


  Serial.begin(9600);
}

void loop() {
  //Serial.print(PINB);
  if(Test != Line){
    Serial.print((char*)Line);
    //Serial.write(Line);
    Line = 0;
  }
//delay(250);
}

ISR(PCINT0_vect) {
//Serial.print(PINB);
mask = PINB;
   if ((mask | 0b11111011) == 0b11111011 ){
    Line = 0x02;
  } 
 
  if ((mask | 0b11111110) == 0b11111110){
    Line = 0x00;
  }
  if ((mask | 0b11111101) == 0b11111101){ 
    Line = 0x01;
  }
  
    if ((mask | 0b11110111) == 0b11110111 ){
    Line = 0x03; } 

  
  if ((mask | 0b11101111) == 0b11101111 ){
    Line = 0x04;
  }
  if ((mask | 0b11011111) == 0b11011111){
    Line = 0x05;
  }
 if ((mask | 0b10111111) == 0b10111111){
    Line = 0x06;
  } 
  if ((mask  | 0b01111111) == 0b01111111){
    Line = 0x07;
  } 

}

ISR(PCINT2_vect) {
  mask1 = PINK;
  if ((mask1  | 0b11111110)  == 0b11111110){
    Line = 0x08;
  }
  if ((mask1 | 0b11111101)  == 0b11111101){
    Line = 0x09;
  }
  if ((mask1 | 0b11111011) == 0b11111011){
    Line = 0x0A;
  }
if ((mask1 | 0b11110111) == 0b11110111){
    Line = 0x0B;
  }

 if ((mask1 | 0b11101111) == 0b11101111){
    Line = 0x0C;
  }

if ((mask1 | 0b11011111) == 0b11011111){
    Line = 0x0D;
  }

  
if( (mask1 | 0b10111111) == 0b10111111) {
    Line = 0x0E;
  }



}
