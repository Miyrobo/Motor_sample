#include "Wire.h"
#include "motor.h"

void MOTOR::move(int power[4]){
    for(int i=0;i<4;i++){
        power[i]*=m_correction[i]/100;
        if(power[i]>127) power[i]=127;
        else if(power[i]<-128) power[i]=-128;
        Wire.beginTransmission(Address[i]);
        Wire.write(power[i]);
        Wire.endTransmission();
    }
}

void MOTOR::cal(int dir,int speed){
    int MAX_=0;
    for(int i=0;i<4;i++){
        m_speed[i]=sin(radians((dir-m_dir[i])))*1000;
    }
    for(int i=0;i<4;i++){
        if(abs(m_speed[i])>MAX_){
            MAX_=abs(m_speed[i]);
        }
    }
    for(int i=0;i<4;i++){
        m_speed[i]*=speed/MAX_;
    }
}

void MOTOR::stop(){
    for(int i=0;i<4;i++){
        m_speed[i]=0;
    }
    move(m_speed);
}

void encoder::Setpin(int n1,int n2){
    pin[0]=n1;
    pin[1]=n2;
}

void encoder::reset(){
    this->value=0;
}

void encoder::read(){
    bool a=digitalRead(pin[0]),b=digitalRead(pin[1]);
    if(a!=state[0]){
        if(a!=b){
            value++;
        }else{
            value--;
        }
    }else if(b!=state[1]){
        if(a!=b){
            value--;
        }else{
            value++;
        }
    }
    state[0]=a;
    state[1]=b;
}