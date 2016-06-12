#ifndef _Motor_h_Incl_
#define  _Motor_h_Incl_

#include "PID.h"
#include "Encoder.h"
#include "HelperFunctions.h"

class Motor
{
public:
  Motor(int _Pin1, int _Pin2, int EncoderPin);

  bool Execute();
  void SetDesiredSpeed(int _speed);
  float GetDesiredSpeed();
  float GetActualSpeed();
  void SetPWM(float _PWM, bool Direction); //True is forward

private:
  int Pin1, Pin2;
  float speed, desiredSpeed;
  float PWM;

  int EncoderSampleTime = 1000;

  PID pid;
  Encoder encoder;

  unsigned long time;
  unsigned long prevTime;
  int prevCount;
};
#endif
