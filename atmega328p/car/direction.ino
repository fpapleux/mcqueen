
#include <Servo.h>

#define MAXLEFT   1000
#define MAXRIGHT  2000
#define MIDDLE    1500
#define DIRPIN    9

Servo dir;

void dir_init () {
  dir.attach (DIRPIN);
}

void dir_set (int pulse) {
  dir.writeMicroseconds (pulse);
}

void dir_leftPct (int pct) {
  dir.writeMicroseconds ( int( double(MIDDLE - ( double(MIDDLE-MAXLEFT)*(double(pct)/100) ))) );
}

void dir_rightPct (int pct) {
  dir.writeMicroseconds ( MIDDLE + ( (MAXRIGHT-MIDDLE)*(pct/100) ) );
}

void dir_straight () {
  dir.writeMicroseconds ( MIDDLE );
}


