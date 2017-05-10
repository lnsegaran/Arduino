#include <SevenSegmentDisplay.h>

SevenSegmentDisplay ssd;
int number = 120;
int increment = 1;

unsigned long currentTime;
unsigned long loopTime;
const int pin_A = 10;  // pin 12
const int pin_B = 11;  // pin 11
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);
  SevenSegmentDisplay ssd = SevenSegmentDisplay();
  currentTime = millis();
  loopTime = currentTime; 
}

void loop() {
  // put your main code here, to run repeatedly:
  writeNumber(number);  
  checkRotary();
}

void writeNumber(int number){
  ssd.setNumber(number);
  ssd.writeNumber();
}

void checkRotary(){
  currentTime = millis();
  if(currentTime >= (loopTime + 5)){
    // 5ms since last check of encoder = 200Hz  
    encoder_A = digitalRead(pin_A);    // Read encoder pins
    encoder_B = digitalRead(pin_B);   
    if((!encoder_A) && (encoder_A_prev)){
      // A has gone from high to low 
      if(encoder_B) {
        // B is high so clockwise
        // increase the brightness, dont go over 255
        if(number + increment <= 999) number += increment;               
      }   
      else {
        // B is low so counter-clockwise      
        // decrease the brightness, dont go below 0
        if(number - increment >= 0) number -= increment;               
      }   

    }   
    encoder_A_prev = encoder_A;     // Store value of A for next time    
       
    loopTime = currentTime;  // Updates loopTime

    writeNumber(number);
  }
}

