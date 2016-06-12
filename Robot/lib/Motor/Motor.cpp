#include "Motor.h"
#include "Arduino.h"

Motor::Motor(int _Pin1, int _Pin2, int EncoderPin){
  pid.SetUp(&speed, &PWM, &desiredSpeed, 2, 0.01, 0.5, 500, 255, 0);
  encoder.SetPin(EncoderPin);

  Pin1 = _Pin1;
  Pin2 = _Pin2;

  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);

  digitalWrite(Pin1, LOW);
  analogWrite(Pin2, 0);
}

bool Motor::Execute(){
  encoder.CheckEncoder();
  GetActualSpeed();

  if (pid.Compute()) {
    SetPWM(PWM, true);
  }

  return true;
}

void Motor::SetDesiredSpeed(int _speed){
  desiredSpeed = _speed;
}

void Motor::SetPWM(float _PWM, bool Direction){
  PWM = _PWM;
  analogWrite(Pin1, (int)PWM); //:TODO: Change Pin
  digitalWrite(Pin2, HIGH);
}

float Motor::GetDesiredSpeed(){
  return desiredSpeed;
}

float Motor::GetActualSpeed(){
  time = millis();
  if (time - prevTime >= 1000){
    speed = (encoder.GetCount() - prevCount) / (time - prevTime);
    prevTime = time;
    prevCount = encoder.GetCount();
  }
  return speed;
}
