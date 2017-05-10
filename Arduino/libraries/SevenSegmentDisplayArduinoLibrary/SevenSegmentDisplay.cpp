#include "SevenSegmentDisplay.h" //include the declaration for this class

SevenSegmentDisplay::SevenSegmentDisplay() {
	setup();
}

SevenSegmentDisplay::SevenSegmentDisplay(int a, int b, int c, int d, int e, int f, int g, int huns, int tens, int ones)
{
	A = a;
	B = b;
	C = c;
	D = d;
	E = e;
	F = f;
	G = g;
	HUNS = huns;
	TENS = tens;
	ONES = ones;
	setup();
}

SevenSegmentDisplay::~SevenSegmentDisplay()
{
}

void SevenSegmentDisplay::writeNumber(int number) {
	int powerof = getNumberOfDigits(number);
	powerof--;
	int mod = power(10, powerof);
	
	for (int i = 0; i <= powerof; i++) {
		setunit(i, powerof);
		int digit = number / mod;
		showDigit(digit);
		number = number % mod;
		mod = mod / 10;
		low();
	}
}

void SevenSegmentDisplay::showDigit(int num) {
	switch (num) {
	case 0: zero();
		break;
	case 1: one();
		break;
	case 2: two();
		break;
	case 3: three();
		break;
	case 4: four();
		break;
	case 5: five();
		break;
	case 6: six();
		break;
	case 7: seven();
		break;
	case 8: eight();
		break;
	case 9: nine();
		break;
	}
}

void SevenSegmentDisplay::setunit(int i, int powerof) {
	int powertake = powerof - i;
	int mod = power(10, powertake);

	switch (mod) {
		case 100: hundreds(); // 100
			break;
		case 10: tens(); // 10
			break;
		case 1: ones(); // 1
			break;
	}
}

int SevenSegmentDisplay::power(int num, int power) {
	int returnnum = num;

	if (power == 0)
		return 1;

	for (int i = 1; i < power; i++)
	{
		returnnum = returnnum * num;
	}
	return returnnum;
}

void SevenSegmentDisplay::low()
{
	digitalWrite(A, LOW);
	digitalWrite(B, LOW);
	digitalWrite(C, LOW);
	digitalWrite(D, LOW);
	digitalWrite(E, LOW);
	digitalWrite(F, LOW);
	digitalWrite(G, LOW);
	digitalWrite(HUNS, LOW);
	digitalWrite(TENS, LOW);
	digitalWrite(ONES, LOW);
}

void SevenSegmentDisplay::hundreds()
{
	 digitalWrite(TENS,LOW);
	 digitalWrite(ONES,LOW);
	 digitalWrite(HUNS,HIGH);
}

void SevenSegmentDisplay::tens()
{
	 digitalWrite(HUNS,LOW);
	 digitalWrite(ONES,LOW);
	 digitalWrite(TENS,HIGH);
}

void SevenSegmentDisplay::ones()
{
	 digitalWrite(HUNS,LOW);
	 digitalWrite(TENS,LOW);
	 digitalWrite(ONES,HIGH);
}

unsigned SevenSegmentDisplay::getNumberOfDigits(unsigned i) {
	return i > 0 ? (int)log10((double)i) + 1 : 1;
}

void SevenSegmentDisplay::setup() {
	 pinMode(A, OUTPUT); //make that pin an OUTPUT
	 pinMode(B, OUTPUT); //make that pin an OUTPUT
	 pinMode(C, OUTPUT); //make that pin an OUTPUT
	 pinMode(D, OUTPUT); //make that pin an OUTPUT
	 pinMode(E, OUTPUT); //make that pin an OUTPUT
	 pinMode(F, OUTPUT); //make that pin an OUTPUT
	 pinMode(G, OUTPUT); //make that pin an OUTPUT
	 pinMode(HUNS, OUTPUT); //make that pin an OUTPUT
	 pinMode(TENS, OUTPUT); //make that pin an OUTPUT
	 pinMode(ONES, OUTPUT); //make that pin an OUTPUT
}

void SevenSegmentDisplay::one() {
	 digitalWrite(A,LOW);
	 digitalWrite(D,LOW);
	 digitalWrite(E,LOW);
	 digitalWrite(F,LOW);
	 digitalWrite(G,LOW);
	 digitalWrite(B,HIGH);
	 digitalWrite(C,HIGH);
}

void SevenSegmentDisplay::two() {
	 digitalWrite(C,LOW);
	 digitalWrite(F,LOW);
	 digitalWrite(A,HIGH);
	 digitalWrite(B,HIGH);
	 digitalWrite(D,HIGH);
	 digitalWrite(E,HIGH);
	 digitalWrite(G,HIGH);
}

void SevenSegmentDisplay::three() {
	 digitalWrite(E,LOW);
	 digitalWrite(F,LOW);
	 digitalWrite(A,HIGH);
	 digitalWrite(B,HIGH);
	 digitalWrite(C,HIGH);
	 digitalWrite(D,HIGH);
	 digitalWrite(G,HIGH);
}

void SevenSegmentDisplay::four() {
	 digitalWrite(A,LOW);
	 digitalWrite(D,LOW);
	 digitalWrite(E,LOW);
	 digitalWrite(B,HIGH);
	 digitalWrite(C,HIGH);
	 digitalWrite(F,HIGH);
	 digitalWrite(G,HIGH);
}

void SevenSegmentDisplay::five() {
	 digitalWrite(B,LOW);
	 digitalWrite(E,LOW);
	 digitalWrite(A,HIGH);
	 digitalWrite(C,HIGH);
	 digitalWrite(D,HIGH);
	 digitalWrite(F,HIGH);
	 digitalWrite(G,HIGH);
}

void SevenSegmentDisplay::six() {
	 digitalWrite(B,LOW);
	 digitalWrite(A,HIGH);
	 digitalWrite(C,HIGH);
	 digitalWrite(D,HIGH);
	 digitalWrite(E,HIGH);
	 digitalWrite(F,HIGH);
	 digitalWrite(G,HIGH);
}

void SevenSegmentDisplay::seven() {
	 digitalWrite(D,LOW);
	 digitalWrite(E,LOW);
	 digitalWrite(F,LOW);
	 digitalWrite(G,LOW);
	 digitalWrite(A,HIGH);
	 digitalWrite(B,HIGH);
	 digitalWrite(C,HIGH);
}

void SevenSegmentDisplay::eight() {
	 digitalWrite(A,HIGH);
	 digitalWrite(B,HIGH);
	 digitalWrite(C,HIGH);
	 digitalWrite(D,HIGH);
	 digitalWrite(E,HIGH);
	 digitalWrite(F,HIGH);
	 digitalWrite(G,HIGH);
}

void SevenSegmentDisplay::nine() {
	 digitalWrite(E,LOW);
	 digitalWrite(A,HIGH);
	 digitalWrite(B,HIGH);
	 digitalWrite(C,HIGH);
	 digitalWrite(D,HIGH);
	 digitalWrite(F,HIGH);
	 digitalWrite(G,HIGH);
}

void SevenSegmentDisplay::zero() {
	 digitalWrite(G,LOW);
	 digitalWrite(A,HIGH);
	 digitalWrite(B,HIGH);
	 digitalWrite(C,HIGH);
	 digitalWrite(D,HIGH);
	 digitalWrite(E,HIGH);
	 digitalWrite(F,HIGH);
}