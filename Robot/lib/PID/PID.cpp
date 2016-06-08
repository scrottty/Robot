#include "PID.h"
#include "Arduino.h"
#include "HelperFunctions.h"

PID::PID(float _Kp, float _Ki, float _Kd) {
  Kp = _Kp;
  Ki = _Ki;
  Kd = _Kd;
  integral = 0;
  derivative = 0;
  prevTime = millis();
  error = 0;
  prevError = error;
}

int PID::calcOutput(float setpoint, float currentVal){

  //Calc Error
  error = setpoint - currentVal;

  //Integral Calculation
  integral = integral + error;
  integral = FitToBounds(integral, 999999999, 0); // TODO: Adjust

  //Derivative Calc
  // TODO: Adjust derivative clac time, set to 2HZ
  time = millis();
  if (time - prevTime >= 500) {
    derivative = (error - prevError) / (time - prevTime);
    derivative = (float)derivative;
    derivative = FitToBounds(derivative, 999999999, 0); // TODO: Adjust
  }

  output = Kp * error + Ki * integral + Kd * derivative;

  return output;

}
