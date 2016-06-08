#include "Motor.h"
#include "PID.h"
#include "Arduino.h"
#include "HelperFunctions.h"

Motor::Motor(int _Pin1, int _Pin2, int EncoderPin) {
  Pin1 = _Pin1;
  Pin2 = _Pin2;

  thisEncoder.SetPin(EncoderPin);
  speed = 0;
  desiredSpeed = 0;

}

void Motor::Execute(){

  CalcSpeed();

}

void Motor::SetSpeed(float _desiredSpeed){
  desiredSpeed = _desiredSpeed;
}

void Motor::CalcSpeed(){
  time = millis();
  if (prevTime - time > 500){ //2HZ speed calc
    speed = (thisEncoder.GetCount() - prevEncoderCount) / (time - prevTime);
    speed = (float)speed;
    prevTime = time;
    prevEncoderCount = thisEncoder.GetCount();
  }

}

float Motor::GetSpeed(){
  return speed;
}
