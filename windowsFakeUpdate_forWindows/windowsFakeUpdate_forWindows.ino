#include "Keyboard.h"

#define LED_WAITING 11
#define LED_EXPLOITING 12
#define LED_DONE 13
boolean state = true;
Keyboard key;

void setup(){
    Serial.begin(9600);
    delay(1000);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);
    pinMode(5,INPUT);
    digitalWrite(11,HIGH);
}

void loop(){
  delay(1000);
  if ((digitalRead(5) == HIGH) && state){
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    key.WINDOWS(r);
    key.DELAY(100);
    key.DELAY(1000);
    key.STRING("powershell Start-Process 'chrome.exe' 'http://fakeupdate.net/win10/index.html'");
    key.DELAY(100);
    key.ENTER();
    key.DELAY(1000);
    key.FULL_WINDOW();
    digitalWrite(12,LOW);
    key.DELAY(100);
    digitalWrite(13,HIGH);
    state = false;
  }

}
