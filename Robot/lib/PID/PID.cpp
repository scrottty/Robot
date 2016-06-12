#include "PID.h"
#include "Arduino.h"

PID::PID() {}

void PID::SetUp(float *_Input, float *_Output, float *_Setpoint,
                float _Kp, float _Ki, float _Kd, float _SampleTime,
                float _maxOutput, float _minOutput) {
  Input = _Input;
  Output = _Output;
  Setpoint = _Setpoint;

  maxOutput = _maxOutput;
  minOutput = _minOutput;

  SampleTime = _SampleTime;
  SampleTimeInSec = SampleTime / 1000;

  Kp = _Kp;
  Ki = _Ki;
  Kd = _Kd;
  integral = 0;
  derivative = 0;
  prevTime = millis();
  error = 0;
  prevError = error;

}

bool PID::Compute(){
// Return if computed, false otherwise
  time = millis();
  if (time - prevTime >= SampleTime) {

    error = *Setpoint - *Input;

    integral += error * SampleTimeInSec;

    derivative = (error - prevError) / SampleTimeInSec;

    integral = FitToBounds(integral, maxIntegral, minIntegral); //TODO: Adjust
    derivative = FitToBounds(derivative, maxDerivative, minDerivative); //TODO: Adjust

    *Output = Kp * error + Ki * integral + Kd * derivative;
    *Output = FitToBounds(*Output, maxOutput, minOutput);

    prevTime = millis();
    prevError = error;

    return true;

  }
  else
    return false;
}

void PID::SetBuildUpLimits(float _maxIntegral, float _minIntegral,
                            float _maxDerivative, float _minDerivative){

  maxIntegral = _maxIntegral;
  minIntegral = _minIntegral;

  maxDerivative = _maxDerivative;
  minDerivative = _minDerivative;
}

float PID::GetKp() {
  return Kp;
}

float PID::GetKi() {
  return Ki;
}

float PID::GetKd() {
  return Kd;
}
