#include <Arduino.h>
#include <Servo.h>

#define PIR_PIN 6

unsigned long last_time_opened = 0;
unsigned long last_time_closed = 0;

Servo servo;

void setup()
{
  pinMode(PIR_PIN, INPUT);
  servo.attach((short)2);
  servo.write(0);
}

void loop()
{
  unsigned long cur_time = millis();
  if (digitalRead(PIR_PIN) == HIGH)
  {
    if (cur_time - last_time_opened >= 2000)
    {
      last_time_opened = cur_time;
      servo.write(90);
    }

    if (cur_time - last_time_closed >= 4000)
    {
      last_time_closed = cur_time;
      servo.write(0);
    }
  }
}
