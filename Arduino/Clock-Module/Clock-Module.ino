#include <SevenSegmentDisplay.h>
#include <TimerOne.h>

SevenSegmentDisplay ssd;
int tempo = 60;
int increment = 1;
long mS;
long duty = 10;
long highDutymS;
long lowDutymS;
long check;
long count = 0;

int state = HIGH;

unsigned long currentTime;
unsigned long loopTime;
const int output_A = 12;
const int rotary_A = 2;
const int rotary_B = 3;
const int PWM = A3;
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev=0;

void setup() {
  calculateFrequency();
  
  pinMode(rotary_A, INPUT);
  pinMode(rotary_B, INPUT);
  pinMode(output_A, OUTPUT);
  SevenSegmentDisplay ssd = SevenSegmentDisplay();
  currentTime = millis();
  loopTime = currentTime; 
  Serial.begin(9600);

  // Initialize the Timer1
  Timer1.initialize(10); // set a timer of length 1 microseconds
  Timer1.attachInterrupt(outputFrequency); // attach the service routine here
  attachInterrupt(digitalPinToInterrupt(2), checkRotary, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(3), checkRotary, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  ssd.writeNumber(tempo);
  calculateFrequency();
  //checkRotary();
}

int calculateFrequency(){
  //Serial.print("tempo = ");
  //Serial.println(tempo);
  float frequency = (float)tempo / (float)60;
  //Serial.print("frequency = ");
  //Serial.println(frequency);
  float seconds = (float)1 / frequency;
  //Serial.print("seconds = ");
  //Serial.println(seconds);
  float mSFloat = seconds * (float)100000;
  //Serial.print("mSFloat = ");
  //Serial.println(mSFloat);
  //  mS = (long)mSFloat;
  //  Serial.print("mS = ");
  //  Serial.println(mS);
  
  float dutycycle = analogRead(PWM);
  dutycycle = map(dutycycle, 0, 1023, 10, 90);
  Serial.print("dutycycle = ");
  Serial.println(dutycycle);
  
  //middle value
  float dutymSFloat = (float)mSFloat / (float)100 * (float)dutycycle;
//  Serial.print("dutymSFloat = ");
//  Serial.println(dutymSFloat);
   highDutymS = (long)dutymSFloat;
//  Serial.print("dutymS = ");
//  Serial.println(dutymS);
  
  //after value
  float afterDutymSFloat = mSFloat - dutymSFloat;
//  Serial.print("afterDutymSFloat = ");
//  Serial.println(afterDutymSFloat);  
   lowDutymS = (long)afterDutymSFloat;
//  Serial.print("afterDutymS = ");
//  Serial.println(afterDutymS);
  
  //Serial.print("dutymS = ");
  //Serial.println(dutymS);
  
}

void outputFrequency(){
  count++;
  if(state == HIGH)
    check = highDutymS;
  else 
    check = lowDutymS;
  
  if(count <= check){
    return;
  }
  digitalWrite(output_A, state);
  state = state == HIGH ? LOW : HIGH;
  count = 0;
}

void checkRotary(){
  currentTime = millis();
  if(currentTime >= (loopTime + 5)){
    // 5ms since last check of encoder = 200Hz  
    encoder_A = digitalRead(rotary_A);    // Read encoder pins
    encoder_B = digitalRead(rotary_B);   
    if((!encoder_A) && (encoder_A_prev)){
      // A has gone from high to low 
      if(encoder_B) {
        // B is high so clockwise
        // increase the brightness, dont go over 255
        if(tempo + increment <= 999) tempo += increment;               
      }   
      else {
        // B is low so counter-clockwise      
        // decrease the brightness, dont go below 0
        if(tempo - increment >= 0) tempo -= increment;               
      }   

    }   
    encoder_A_prev = encoder_A;     // Store value of A for next time    
       
    loopTime = currentTime;  // Updates loopTime
  }
}
