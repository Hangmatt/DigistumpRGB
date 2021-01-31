/*
I do not lay claim on any form of intellectual "property." Use how you please...

This reads some analog value and writes PWM to another pin. See readme for a tiny bit more detail.
*/

#include <Arduino.h>

// When using a pin as an analog in, it is named differently from when being used as a digital or analog output.
const int potR  = 0; //PB5;PB5;ADC0
const int potG  = 3; //PB3;P3;ADC3
const int potB  = 2; //PB2;P2;ADC1

// three pwm outputs
const int ledR = PB0;
const int ledG = PB1;
const int ledB = PB4;

// variables to hold the readings from the potentiometers
int dataR;
int dataG;
int dataB;

// variables to hold the mapped readings; the PWM values
int r;
int g;
int b;

// inputs do not have to be set when using the Digispark
void setup() {
    // pinMode(potR, INPUT);
    // pinMode(potG, INPUT);
    // pinMode(potB, INPUT);
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);
}

//Read the potentiometer value, map the 0-1024 scale to a 0-255 scale, write the value to the output pin. Repeat for other colors.
void loop() {
  dataR = analogRead(potR);
  r = map(dataR, 0, 1024, 0, 255);
  analogWrite(ledR, r);
  dataG = analogRead(potG);
  g = map(dataG, 0, 1024, 0, 255);
  analogWrite(ledG, g);
  dataB = analogRead(potB);
  b = map(dataB, 0, 1024, 0, 255);
  analogWrite(ledB, b);
}