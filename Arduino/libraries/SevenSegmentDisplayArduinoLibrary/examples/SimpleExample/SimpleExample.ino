#include <SevenSegmentDisplay.h>

SevenSegmentDisplay ssd;

void setup() {
  // put your setup code here, to run once:
 
  SevenSegmentDisplay ssd = SevenSegmentDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  ssd.setNumber(456);
  ssd.writeNumber();
}

