
#include "motors.h"

// ###########################################################################

void initMotors()
{
    pinMode(myM1IN1,OUTPUT);
    pinMode(myM1IN2,OUTPUT);
    pinMode(myM1FB,INPUT);
    pinMode(mynSF,INPUT);
    pinMode(mynD2,OUTPUT);
    digitalWrite(mynD2,HIGH); // default to on
    pinMode(myD1,OUTPUT);
    digitalWrite(myD1,LOW); // default to on

    #if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
        // Timer 1 configuration
        // prescaler: clockI/O / 1
        // outputs enabled
        // phase-correct PWM
        // top of 400
        //
        // PWM frequency calculation
        // 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20kHz
        TCCR1A = 0b10100000;
        TCCR1B = 0b00010001;
        ICR1 = 400;
    #endif
}

// ###########################################################################

void setSpeed(int speed)
{
    if (speed > 400)  // Max PWM dutycycle
        speed = 400;
    if (speed < -400)  // Max PWM dutycycle
        speed = -400;

    if (speed > 0)
    {
        OCR1A = speed;
        analogWrite(myM1IN1, speed);
        digitalWrite(myM1IN2, LOW);
    }
    else
    {
        OCR1A = -speed;
        analogWrite(myM1IN2, -speed);
        digitalWrite(myM1IN1, LOW);
    }
}

// ###########################################################################
