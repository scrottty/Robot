#ifndef _PID_h_Incl_
#define  _PID_h_Incl_

class PID
{
public:
  PID(float _Kp, float _Ki, float _Kd);
  int calcOutput(float setpoint, float currentVal);


private:
  float Kp, Ki, Kd;
  int output;
  float integral;
  float derivative;

  float error;
  float prevError;

  unsigned long prevTime;
  unsigned long time;
};

#endif
