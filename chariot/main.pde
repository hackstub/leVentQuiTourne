
/**
 *	@author Alexandre Aubin
*/

#include "motors.h"

// ####################################################################

#define VITESSE_ROTATION 300 
#define ANGLE_TO_TIME_PLUS  (700)
#define ANGLE_TO_TIME_MINUS (700 * 1.07)

void tourner(long int angle)
{
    if (angle < 0)
    {
        setSpeed(-VITESSE_ROTATION);
        delay(-angle * ANGLE_TO_TIME_MINUS);
    }
    else
    {
        setSpeed(VITESSE_ROTATION);
        delay(angle * ANGLE_TO_TIME_PLUS);
    }

    setSpeed(0);
}

// ####################################################################

void setup()
{
    Serial.begin(115200);
    delay(5);
    Serial.println("Initialization");
    initMotors();
}

// ####################################################################

void loop()
{

    tourner(-90);
    delay(10000);
    tourner(20);
    delay(10000);
    tourner(-60);
    delay(10000);
    tourner(40);
    delay(10000);
    tourner(-10);
    delay(10000);
    tourner(45);
    delay(10000);
    tourner(-10);
    delay(10000);
    tourner(65);
    delay(10000);
    
   // while (1) { }
}

// ####################################################################
