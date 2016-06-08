#ifndef _Encoder_h_Incl_
#define  _Encoder_h_Incl_

class Encoder
{
public:
  Encoder();
  void SetPin(int _pin);
  void CheckEncoder(void);
  int GetCount();


private:
  int pin;
  int count;
  int newReading;
  bool CurrentStatus;

  int UpperTrigger;
  int LowerTrigger;
};
#endif
