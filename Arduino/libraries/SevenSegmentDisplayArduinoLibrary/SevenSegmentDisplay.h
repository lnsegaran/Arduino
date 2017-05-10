#ifndef SevenSegmentDisplay_H
#define SevenSegmentDisplay_H

#include <Arduino.h>
#include <Math.h>

class SevenSegmentDisplay {
public:
	SevenSegmentDisplay();
	SevenSegmentDisplay(int a, int b, int c, int d, int e, int f, int g, int huns, int tens, int ones);
	~SevenSegmentDisplay();

	void writeNumber(int num);

private:
	int A = 4, B = 5, C = 6, D = 7, E = 8, F = 9, G = 10, Number;
	int HUNS = A0, TENS = A1, ONES = A2;

	void setup();

	unsigned getNumberOfDigits(unsigned num);
	int power(int num, int power);
		
	void showDigit(int num);
	void setunit(int i, int powerof);

	void low();
	void hundreds();
	void tens();
	void ones();
	void one();
	void two();
	void three();
	void four();
	void five();
	void six();
	void seven();
	void eight();
	void nine();
	void zero();
};

#endif
