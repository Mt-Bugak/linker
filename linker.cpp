#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3);   //bluetooth module Tx:Digital 2 Rx:Digital 3
char a;
int i;
int white = 11;
int blue = 10;
int green = 9;
void setup() {
  pinMode(8, OUTPUT);    //HC-05
  pinMode(13, OUTPUT);
  digitalWrite(8,HIGH);
  
  Serial.begin(9600);
  BTSerial.begin(38400);
  Serial.println("ATcommand");  //ATcommand Start
}

void loop() {

  if (BTSerial.available())
  {
    a = BTSerial.read();
    Serial.write(a);
    if (a=='q') {
      white_on();
    }
    else if(a=='w'){
      white_off();
    }
    else if(a=='e'){
      white_flash();
    }
    else if(a=='a'){
      blue_on();
    }
    else if(a=='s'){
      blue_off();
    }    
    else if(a=='z'){
      green_on();
    }    
    else if(a=='x'){
      green_off();
    }
  }
  if (Serial.available())
  {
    BTSerial.write(Serial.read());
  }
  
}

void white_flash(){
  int i = 0;
  while(true){
    if (BTSerial.available()){
      a = BTSerial.read();
      Serial.write(a);
      if (a!='e') {
        break;
      }
    }
    while(i<255){
      analogWrite(white, i);
      delay(10);
      i++;
    }
    while(i>0){
      analogWrite(white, i);
      delay(3);
      i--;
    }
  }
}
void white_on(){
  int i = 0;
  while(i<=255){
    analogWrite(white, i);
    delay(15);
    i++;
  }
}
void white_off(){
  int i = 255;
  while(i>=0){
    analogWrite(white, i);
    delay(5);
    i--;
  }
}
void green_on(){
  int i = 0;
  while(i<=255){
    analogWrite(green, i);
    delay(15);
    i++;
  }
}
void green_off(){
  int i = 255;
  while(i>=0){
    analogWrite(green, i);
    delay(5);
    i--;
  }
}
void blue_on(){
  int i = 0;
  while(i<=255){
    analogWrite(blue, i);
    delay(15);
    i++;
  }
}
void blue_off(){
  int i = 255;
  while(i>=0){
    analogWrite(blue, i);
    delay(5);
    i--;
  }
}
