#include <LiquidCrystal.h>

#define LEDR 13
#define LEDG 10
#define LEDB 11
#define BUTTON 6
#define BUTTON2 2

#define pinPot A0
#define pinPwm 5



LiquidCrystal lcd(12, 9, 8, 7, 4, 3);

int BUTTONSTATE = 0;
char i[] = {13, 10, 11};
int x = 0;

void setup()
{
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  
  int pwm; 
  pwm = pwmLer(pinPot); 
  analogWrite(pinPwm, pwm);
  
  BUTTONSTATE = digitalRead(BUTTON);
  
  while(BUTTONSTATE == true){
    
    if(digitalRead(BUTTON2)){
    
      BUTTONSTATE = false;
    
    }
    
    digitalWrite(i[x], HIGH);
  	delay(1000);
 
  	digitalWrite(i[x], LOW);
  	delay(1000);
    
    x++;
    
    if(x > 2){
    
      x = 0;
    
    }
  }  
}

int pwmLer(byte canal){

  	unsigned int AD;
  	int ADpwm;
  
    AD = analogRead(canal);
  	ADpwm = AD / 4;
	return ADpwm;
};