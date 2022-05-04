//www.elegoo.com
//2016.12.9

#include "IRremote.h"


#define ENABLE_L 5
#define DIRA_L 3
#define DIRB_L 4

#define ENABLE_R 10
#define DIRA_R 9
#define DIRB_R 8

int R_speed = 0;
int L_speed = 0;

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void R_set_speed(int s){
  int ab = s;
  R_speed=ab;
  if (s >= 0){
    R_speed=s;
    digitalWrite(DIRA_R,HIGH);
    digitalWrite(DIRB_R, LOW);
  }
  else{
    ab*=-1;
    digitalWrite(DIRA_R,LOW);
    digitalWrite(DIRB_R, HIGH);
 
  }
  
  analogWrite(ENABLE_R, ab);
}

void L_set_speed(int s){
  L_speed=s;
  int ab = s;
  if (s >= 0){
    digitalWrite(DIRA_L,HIGH);
    digitalWrite(DIRB_L, LOW);
  }
  else{
    ab*=-1;
    digitalWrite(DIRA_L,LOW);
    digitalWrite(DIRB_L, HIGH);

  }
  
  analogWrite(ENABLE_L, ab);
}

void turnRight(){
  if (L_speed<=0){
  L_set_speed(200);
  R_set_speed(-200);
  }
  else{
    L_set_speed(250);
    R_set_speed(180);
  }
}

void turnLeft(){
  if (L_speed<=0){
  L_set_speed(-200);
  R_set_speed(200);
  }
  else {
    R_set_speed(250);
    L_set_speed(180);
  }
}

/*-----( Function )-----*/
void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{

  switch(results.value)

  {
  case 0xFFA25D: Serial.println("POWER"); break;
  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  case 0xFF629D: Serial.println("VOL+"); break;
  case 0xFF22DD: Serial.println("FAST BACK");    break;
  case 0xFF02FD: Serial.println("PAUSE");    break;
  case 0xFFC23D: Serial.println("FAST FORWARD");   break;
  case 0xFFE01F: Serial.println("DOWN");    break;
  case 0xFFA857: Serial.println("VOL-");    break;
  case 0xFF906F: Serial.println("UP");    break;
  case 0xFF9867: Serial.println("EQ");   L_set_speed(500); R_set_speed(500); break;
  case 0xFFB04F: Serial.println("ST/REPT");    break;
  case 0xFF6897: Serial.println("0");    break;
  case 0xFF30CF: Serial.println("1");    break;
  case 0xFF18E7: Serial.println("2");    L_set_speed(150); R_set_speed(150); break;
  case 0xFF7A85: Serial.println("3");    break;
  case 0xFF10EF: Serial.println("4");    turnLeft(); break;
  case 0xFF38C7: Serial.println("5");    L_set_speed(0); R_set_speed(0); break;
  case 0xFF5AA5: Serial.println("6");    turnRight(); break;
  case 0xFF42BD: Serial.println("7");    break;
  case 0xFF4AB5: Serial.println("8");    L_set_speed(-250); R_set_speed(-250); break;
  case 0xFF52AD: Serial.println("9");    break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  

  default: 
    Serial.println(" other button : ");
    Serial.println(results.value);

  }// End Case

  delay(500); // Do not get immediate repeat


} //END translateIR
void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  pinMode(ENABLE_R,OUTPUT);
  pinMode(DIRA_R,OUTPUT);
  pinMode(DIRB_R,OUTPUT);

  pinMode(ENABLE_L,OUTPUT);
  pinMode(DIRA_L,OUTPUT);
  pinMode(DIRB_L,OUTPUT);

  
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver

  for (int i=2; i<7; ++i){
    pinMode(i,OUTPUT);
  }

//R_set_speed(120);
//L_set_speed(120);
}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
}/* --(end main loop )-- */
