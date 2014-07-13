
#include <Servo.h>

Servo wheel;
int i;

void setup()
{
  wheel.attach(9);
  i = 0;
}

void loop()
{
  wheel.writeMicroseconds(1500);
  delay(1500);
  if (i < 4) {
    wheel.writeMicroseconds(1000);
    delay(1500);
    wheel.writeMicroseconds(1500);
    delay(1500);
    wheel.writeMicroseconds(2000);
    delay(1500);
    i++;
  }
}

