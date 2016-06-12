#include "Arduino.h"
#include "Servo.h"
#include "Ultrasonic.h"
#include "Motor.h"


#ifndef UltrasonicPin
#define  UltrasonicPin 31
#endif

#ifndef Motor1Pin1
#define  Motor1Pin1 9
#endif

#ifndef Motor1Pin2
#define  Motor1Pin2 10
#endif

#ifndef Motor1EncoderPin
#define  Motor1EncoderPin 20
#endif

Ultrasonic ultrasonic(UltrasonicPin);
Motor leftMotor(Motor1Pin1, Motor1Pin2, Motor1EncoderPin);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0){
    int PWMVal = Serial.parseInt();
    Serial.print("PWM Value: ");
    Serial.println(PWMVal);
  //  analogWrite(PWMPin1, HIGH);
  //  analogWrite(PWMPin2, PWMVal);
  }
}
