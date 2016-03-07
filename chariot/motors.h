
#ifndef _MOTORS_H_
#define _MOTORS_H_

#include "Arduino.h"

// ############################################################################

#define mynSF 12
#define mynD2 4
#define myD1  5

#define myM1IN1 9
#define myM1IN2 10
#define myM1FB  A0

// ############################################################################

void initMotors();
void setSpeed(int speed);

// ############################################################################

#endif

