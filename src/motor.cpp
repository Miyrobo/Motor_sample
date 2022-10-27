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