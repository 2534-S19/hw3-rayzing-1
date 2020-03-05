/*
 * GPIO.c
 *
 *  Created on:
 *      Author: Raymond Daniels (skeleton code provided by Dr. Thweatt)
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
    GPIO_setAsInputPinWithPullUpResistor( Port1, PIN1 ); //use the inputandpullup/pulldown resistor function instead (3-in-1)

    // Launchpad S2
    GPIO_setAsInputPinWithPullUpResistor( Port1, PIN4 );

    // Boosterpack S1
    GPIO_setAsInputPinWithPullUpResistor( Port5, PIN1 );

    // Boosterpack S2
    GPIO_setAsInputPinWithPullUpResistor( Port3, PIN5 );

    // Launchpad LED1
    GPIO_setAsOutputPin( Port1, PIN0 );

    // Launchpad LED2 Red
    GPIO_setAsOutputPin( Port2, PIN0 );

    // Launchpad LED2 Green
    GPIO_setAsOutputPin( Port2, PIN1 );

    // Launchpad LED2 Blue
    GPIO_setAsOutputPin( Port2, PIN2 );

    // Boosterpack LED Red
    GPIO_setAsOutputPin( Port2, PIN6 );

    // Boosterpack LED Green
    GPIO_setAsOutputPin( Port2, PIN4 );

    // Boosterpack LED Blue
    GPIO_setAsOutputPin( Port5, PIN6 );

    // Turn off all LEDs at the start.
    GPIO_setOutputLowOnPin( Port1, PIN0 );
    GPIO_setOutputLowOnPin( Port2, PIN0 );
    GPIO_setOutputLowOnPin( Port2, PIN1 );
    GPIO_setOutputLowOnPin( Port2, PIN2 );
    GPIO_setOutputLowOnPin( Port2, PIN6 );
    GPIO_setOutputLowOnPin( Port2, PIN4 );
    GPIO_setOutputLowOnPin( Port5, PIN6 );
}


// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    GPIO_getInputPinValue( Port1, PIN1 ); //we want a return input low for pressed correct /**** how do you go INTO  DRIVERLIBRARY function to check it? ***/
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    GPIO_getInputPinValue( Port1, PIN4 );
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    GPIO_getInputPinValue( Port5, PIN1 );
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    GPIO_getInputPinValue( Port3, PIN5 );
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    GPIO_setOutputHighOnPin( Port1, PIN0 );
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    GPIO_setOutputLowOnPin( Port1, PIN0 );
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    GPIO_setOutputHighOnPin( Port2, PIN0 );
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    GPIO_setOutputLowOnPin( Port2, PIN0 );
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    GPIO_setOutputHighOnPin( Port2, PIN1 );
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    GPIO_setOutputLowOnPin( Port2, PIN1 );
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    GPIO_setOutputHighOnPin( Port2, PIN2 );
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    GPIO_setOutputLowOnPin( Port2, PIN2 );
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    GPIO_setOutputHighOnPin( Port2, PIN6 );
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    GPIO_setOutputLowOnPin( Port2, PIN6 );
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    GPIO_setOutputHighOnPin( Port2, PIN4 );
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    GPIO_setOutputLowOnPin( Port2, PIN4 );
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    GPIO_setOutputHighOnPin( Port5, PIN6 );
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    GPIO_setOutputLowOnPin( Port5, PIN6 );
}
