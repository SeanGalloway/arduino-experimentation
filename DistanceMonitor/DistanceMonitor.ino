#include "SR04.h"
#include "LiquidCrystal.h"

#define TRIG_PIN 2
#define ECHO_PIN 3
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);

LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.print("Printing things!!");

Serial.begin(9600);
delay(1000);
Serial.print(sr04.Distance());
}

void loop() {
  // put your main code here, to run repeatedly:

}
