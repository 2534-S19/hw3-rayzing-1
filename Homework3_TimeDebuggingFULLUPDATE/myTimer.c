/*
 * myTimer.c
 *
 *  Created on: 3/2/2020
 *      Author: Raymond Daniels (code skeleton provided by: Prof. Thweatt)
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myTimer.h"

// TODO: Write a function that can intialize a Timer with particular values for pre-scale and count.
// Aliases for the Timers and the preScaler arguments are defined in myTimer.h
void initTimer(unsigned int timer, unsigned int preScaler, unsigned int count)
{
    // For the specified timer and pre-scale value, put the timer in 32-bit periodic mode.
    Timer32_initModule( timer, preScaler, TIMER32_32BIT, TIMER32_PERIODIC_MODE ); // !!! if DRIVERLIB FUNCTION is NOT correct in ANY WAY it will NOT be purple

    // For the specified timer, pass the count value.
    Timer32_setCount( timer, count );

    // For the specified timer, configure the timer to repeat once it elapses.
    Timer32_startTimer( timer, !(ONESHOT) ); //want false so it continues counting
}

// TODO: Write a function that indicates whether Timer0 has expired.
// You have been given a such a function in the lecture slides.
bool timer0Expired(void)
{
    static unsigned int previousSnap = MAX_VALUE; //initializing previous snapshot to the max value (since it starts here anywhere)
    unsigned int currentSnap; //new snapshot
    bool returnValue; //false or true

    currentSnap = Timer32_getValue(TIMER0); //returns value of current timer
    returnValue = (currentSnap > previousSnap); //set to detect whether or not currentsnap has become larger (e.g. CS = 1000 and PS = 0 now)
    previousSnap = currentSnap; //keeps refreshing new snap

    return returnValue; //if true, the timer HAS expired at least once
}

// TODO: Write a function that indicates whether Timer1 has expired.
// This is essentially a copy of the previous function, using a different timer.
// Since we only have two timers, later in the course we will create software timers that use a common time base.
bool timer1Expired(void)
{/*Exact same as TIMER0 but now we check TIMER1*/
    static unsigned int previousSnap = MAX_VALUE;
    unsigned int currentSnap;
    bool returnValue;

    currentSnap = Timer32_getValue(TIMER1);
    returnValue = (currentSnap > previousSnap);
    previousSnap = currentSnap;

    return returnValue;
}
