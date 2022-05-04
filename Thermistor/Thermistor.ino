#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
double LEDpower = 255;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("Yo Jo");
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  pinMode(6, OUTPUT);
  analogWrite(6, 200);
  delay(500);
  analogWrite(6, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int tempReading = analogRead(A0);
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK ))
               * tempK );
  float tempC = tempK - 273.15;
  float tempF = (tempC * 9.0) / 5.0 + 32.0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("temp: ");
  lcd.print(tempF);
  LEDpower = (double)tempF - 65.0;
  LEDpower *= 255.0;
  LEDpower /= 20.0;
  LEDpower = floor(LEDpower);
  analogWrite(3, (int)LEDpower);
  lcd.setCursor(0, 1);
  lcd.print("LED power: ");
  lcd.print(LEDpower);
  delay(500);
}
