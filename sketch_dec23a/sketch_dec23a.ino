// Define Pins
#define BLUE 3 
#define GREEN 5 
#define RED 6
#include "LiquidCrystal.h"
#include "pitches.h"

int red = 255;
int blue =0;
int green = 0;

LiquidCrystal lcd(7,8,9,10,11,12);

int spacesNeeded(int x){
  if (x < 10){
    return 2;
  }
  if (x < 100){
    return 1;
  }
  if (x>99){
    return 0;
  }
}

void printLights(int r, int g, int b){

    
    
    lcd.print("R: ");
    for (int i=0; i<spacesNeeded(r); ++i ){
      lcd.print(" ");
    }
    lcd.print(r);
    lcd.print("  G: ");
    for (int i=0; i<spacesNeeded(g); ++i){
      lcd.print(" ");
    }
    lcd.print(g);
    lcd.setCursor(0,2);
    lcd.print(" B: ");
    for (int i=0; i<spacesNeeded(b); ++i){
      lcd.print(" ");
    }
    lcd.print(b);
 
}

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.print("Hello, World!");



pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
pinMode(A0, OUTPUT);
analogWrite(RED, red);
analogWrite(GREEN, green);
analogWrite(BLUE, blue);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<255; ++i){
    red--;
    green++;
    analogWrite(RED, red);
    analogWrite(GREEN, green);
    delay(50);
    lcd.clear();
   printLights(red, green, blue); 
  }
  for (int i=0; i<255; ++i){
    blue++;
    green--;
    analogWrite(GREEN, green);
    analogWrite(BLUE, blue);
    delay(50);
    lcd.clear();
    printLights(red, green, blue);
  }
  
  for (int i=0; i<255; ++i){
    blue--;
    red++;
    analogWrite(BLUE, blue);
    analogWrite(RED, red);
    delay(50);
    lcd.clear();
    printLights(red, green, blue);
    
  }

}
