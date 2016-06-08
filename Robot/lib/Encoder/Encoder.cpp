#include "Encoder.h"
#include "Arduino.h"

Encoder::Encoder()
{
  UpperTrigger = 750;
  LowerTrigger = 600;
  CurrentStatus = false;
  count = 0;

}

void Encoder::SetPin(int _pin){
  pin = _pin;
  pinMode(pin, INPUT);
}
void Encoder::CheckEncoder() {
  newReading = analogRead(pin);

  if (newReading > UpperTrigger & CurrentStatus == false) {
    count++;
    CurrentStatus = true;
  }
  else if (newReading < LowerTrigger & CurrentStatus == true) {
    count++;
    CurrentStatus = false;
  }
}

int Encoder::GetCount(){
  return count;
}
