#include "Arduino.h"
#include "Servo.h"
#include "Ultrasonic.h"


#ifndef UltrasonicPin
#define  UltrasonicPin 31
#endif

Ultrasonic ultrasonic(UltrasonicPin);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  long Dist;
  ultrasonic.MeasureDist();
  Dist = ultrasonic.GetDistCM();
  Serial.print("Distance: ");
  Serial.print(Dist);
  Serial.println(" cm");
  delay(100);
}
