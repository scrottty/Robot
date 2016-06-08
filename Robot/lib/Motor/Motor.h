#ifndef _Motor_h_Incl_
#define  _Motor_h_Incl_

class Motor
{
public:
  Motor(int _Pin1, int _Pin2);

  void SetSpeed();
  void SetPWM();

private:
  int Pin1, Pin2;
  float speed;


};





#endif
