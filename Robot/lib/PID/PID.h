#ifndef _PID_h_Incl_
#define  _PID_h_Incl_

#include "HelperFunctions.h"

class PID
{
public:
  PID();

  void SetUp(float* _Input, float* _Output, float* _Setpoint,
    float _Kp, float _Ki, float _Kd, float _SampleTime,
    float _maxOutput, float _minOutput);

  bool Compute();

  float GetKp();
  float GetKi();
  float GetKd();

  void SetBuildUpLimits(float _maxIntegral, float _minIntegral,
                        float _maxDerivative, float _minDerivative);

private:
  //PID Constants
  float Kp, Ki, Kd;
  //Pointers to Input values
  float *Output, *Input, *Setpoint;

  //values to be calculated
  float integral;
  float derivative;
  //Error
  float error;
  float prevError;
  //Sample Time
  float SampleTime;
  float SampleTimeInSec;
  //Variable limits
  float maxOutput;
  float minOutput;
  float maxIntegral;
  float minIntegral;
  float maxDerivative;
  float minDerivative;
  //Time variables
  unsigned long prevTime;
  unsigned long time;
};

#endif
