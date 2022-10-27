#include <Arduino.h>
#include "motor.h"
#include "Wire.h"

void pc_control();
int x_speed=0,y_speed=0;

MOTOR motor;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  pc_control();
  motor.cal(degrees(atan2(x_speed,y_speed)),50);
  motor.move(motor.m_speed);
}



void pc_control(){
  if(Serial.available()){
    char key=Serial.read();
    if(key=='w'){
      y_speed=50;
    }else if(key=='s'){
      y_speed=-50;
    }else{
      y_speed=0;
    }
    if(key=='d'){
      x_speed=50;
    }else if(key=='a'){
      x_speed=-50;
    }else{
      x_speed=0;
    }
  }
}