#ifndef _Motor_h_Incl_
#define  _Motor_h_Incl_

#include "Encoder.h"

class Motor
{
public:
  Motor(int _Pin1, int _Pin2, int EncoderPin);
  void Execute();

  void SetSpeed(float _desiredSpeed);
  void SetPWM();
  float GetSpeed();
  void CalcSpeed();

private:
  int Pin1, Pin2;

  int prevEncoderCount;
  unsigned long prevTime;
  unsigned long time;
  float speed;
  float desiredSpeed;

  Encoder thisEncoder;

};





#endif
