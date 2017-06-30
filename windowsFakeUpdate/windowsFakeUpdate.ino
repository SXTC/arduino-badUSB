#include "Keyboard.h"

#define RGB 1 
bool state = true;
Keyboard key;
void waiting();
void exploiting();
void done();

void setup(){
    Serial.begin(9600);
    delay(1000);
    pinMode(3,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(8,INPUT);
    #if defined(RGB)
      waiting();
    #endif
}

void loop(){
  delay(1000);
  if ((digitalRead(8) == HIGH) && state){
    #if defined(RGB)
      exploiting();
    #endif
    //key.ALT_F2();
    key.DELAY(1000);
    //key.STRING("gnome-terminal");
    key.DELAY(100);
    //key.ENTER();
    key.DELAY(1000);
    //key.STRING("google-chrome http://fakeupdate.net/win10/index.html");
    key.DELAY(100);
    //key.ENTER();
    key.DELAY(1000);
    //key.FULL_WINDOW();
    key.DELAY(100);
    #if defined(RGB)
      done();
    #endif
    state = false;
  }

}
void waiting(){
    analogWrite(5,200);
    analogWrite(3,0);
    analogWrite(6,0);
}
void exploiting(){
    analogWrite(5,140);
    analogWrite(3,30);
    analogWrite(6,180);
}
void done(){
    analogWrite(5,0);
    analogWrite(3,0);
    analogWrite(6,200);
}
