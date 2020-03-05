#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned char buttonhistory = UNPRESSED;
    unsigned int previousPress = 0;

    // Stops the Watchdog timer.
    initBoard();

    // Initialize the GPIO.
    // !!! YOU MUST WRITE THIS FUNCTION IN myGPIO.c !!!
    initGPIO();

    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER0, TIMER0_PRESCALER, TIMER0_COUNT);

    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER1, TIMER1_PRESCALER, TIMER1_COUNT); //values to use during runtime. These change between both calls.

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);

        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if( timer0Expired() )
        {
            count0++;
        }

        else
        {
        }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if( timer1Expired() )
        {
            if ( !(checkStatus_BoosterpackS1()) )
                buttonhistory = buttonhistory << 1;
            else
            {
                buttonhistory = buttonhistory << 1;
                buttonhistory += 1;
            }
            //buttonhistory = checkStatus_BoosterpackS1();
        }

        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        unsigned int previousPress = fsmBoosterpackButtonS1( buttonhistory ); //store value so clearly see 1 or 0


        // TODO: If a completed, debounced button press has occurred, increment count1.
        if( previousPress ) //if this is pressed, increment count1, i.e. change BLED state
        {
            count1++;
        }

    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count0)
{
    unsigned int num = 0x00000007;
    //switch statements using cases on and off with GPIO functions
    //switch can be an expression
    //BGR 0 - 7 but mapping it to repeat through these values at 8, 9... etc. b/c unsigned int off red green yellow etc.

    //if set num (0...0111) OR'd with count gives 0-7.
    switch( (num & count0) ) //modulus also an option
    {
        case 0: //turn off all LED2
            GPIO_setOutputLowOnPin( Port2, PIN0 );
            GPIO_setOutputLowOnPin( Port2, PIN1 );
            GPIO_setOutputLowOnPin( Port2, PIN2 );
            break;

        case 1: //turn on red
            GPIO_setOutputHighOnPin( Port2, PIN0 );
            GPIO_setOutputLowOnPin( Port2, PIN1 );
            GPIO_setOutputLowOnPin( Port2, PIN2 );
            break;

        case 2: //turn on green
            GPIO_setOutputLowOnPin( Port2, PIN0 );
            GPIO_setOutputHighOnPin( Port2, PIN1 );
            GPIO_setOutputLowOnPin( Port2, PIN2 );
            break;

        case 3: //turn on green and red
            GPIO_setOutputHighOnPin( Port2, PIN0 );
            GPIO_setOutputHighOnPin( Port2, PIN1 );
            GPIO_setOutputLowOnPin( Port2, PIN2 );
            break;

        case 4: //turn on blue
            GPIO_setOutputLowOnPin( Port2, PIN0 );
            GPIO_setOutputLowOnPin( Port2, PIN1 );
            GPIO_setOutputHighOnPin( Port2, PIN2 );
            break;

        case 5: //turn on blue and red
            GPIO_setOutputHighOnPin( Port2, PIN0 );
            GPIO_setOutputHighOnPin( Port2, PIN2 );
            GPIO_setOutputLowOnPin( Port2, PIN1 );
            break;

        case 6: //turn on blue and green
            GPIO_setOutputLowOnPin( Port2, PIN0 );
            GPIO_setOutputHighOnPin( Port2, PIN1 );
            GPIO_setOutputHighOnPin( Port2, PIN2 );
            break;

        case 7: //turn on blue green and red
            GPIO_setOutputHighOnPin( Port2, PIN0 );
            GPIO_setOutputHighOnPin( Port2, PIN1 );
            GPIO_setOutputHighOnPin( Port2, PIN2 );
            break;

        default:
            GPIO_setOutputLowOnPin( Port2, PIN0 );
            GPIO_setOutputLowOnPin( Port2, PIN1 );
            GPIO_setOutputLowOnPin( Port2, PIN2 );
    }

}

// TODO: Map the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count1)
{
    unsigned int num = 0x00000007;

    switch( (num & count1) ) //modulus also an option
        {
            case 0: //turn off all BLED
                GPIO_setOutputLowOnPin( Port2, PIN6 );
                GPIO_setOutputLowOnPin( Port2, PIN4 );
                GPIO_setOutputLowOnPin( Port5, PIN6 );
                break;

            case 1: //turn on red
                GPIO_setOutputHighOnPin( Port2, PIN6 );
                GPIO_setOutputLowOnPin( Port2, PIN4 );
                GPIO_setOutputLowOnPin( Port5, PIN6 );
                break;

            case 2: //turn on green
                GPIO_setOutputLowOnPin( Port2, PIN6 );
                GPIO_setOutputHighOnPin( Port2, PIN4 );
                GPIO_setOutputLowOnPin( Port5, PIN6 );
                break;

            case 3: //turn on green and red
                GPIO_setOutputHighOnPin( Port2, PIN6 );
                GPIO_setOutputHighOnPin( Port2, PIN4 );
                GPIO_setOutputLowOnPin( Port5, PIN6 );
                break;

            case 4: //turn on blue
                GPIO_setOutputLowOnPin( Port2, PIN6 );
                GPIO_setOutputLowOnPin( Port2, PIN4 );
                GPIO_setOutputHighOnPin( Port5, PIN6 );
                break;

            case 5: //turn on blue and red
                GPIO_setOutputHighOnPin( Port2, PIN6 );
                GPIO_setOutputHighOnPin( Port5, PIN6 );
                GPIO_setOutputLowOnPin( Port2, PIN4 );
                break;

            case 6: //turn on blue and green
                GPIO_setOutputLowOnPin( Port2, PIN6 );
                GPIO_setOutputHighOnPin( Port2, PIN4 );
                GPIO_setOutputHighOnPin( Port5, PIN6 );
                break;

            case 7: //turn on blue green and red
                GPIO_setOutputHighOnPin( Port2, PIN6 );
                GPIO_setOutputHighOnPin( Port2, PIN4 );
                GPIO_setOutputHighOnPin( Port5, PIN6 );
                break;

            default:
                GPIO_setOutputLowOnPin( Port2, PIN6 );
                GPIO_setOutputLowOnPin( Port2, PIN4 );
                GPIO_setOutputLowOnPin( Port5, PIN6 );
        }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory) //buttonpressaction in FSM can go in either state transition
{
    typedef enum state {DOWN, UP} State; //set the state you want
    static State buttonstate = UP; //we want to default to this state on first call every time
    bool pressed = false; //false is going to be 0xFF and true 0x00


    switch( buttonstate ) //check for what state is
    {
        case UP:
            if( buttonhistory == PRESSED ) //hey the button has been held down for a long time
            {
                 buttonstate = DOWN; //let's change the state now
            }
            break;

        case DOWN: //down to up
            if( buttonhistory == UNPRESSED ) //hey the button hasn't been pressed for that long now
            {
                buttonstate = UP; //let's change the state again
                pressed = true; //oh look we're back where we were before (UP-DOWN-UP) that must be a full SINGLE press. Let's make pressed true
                //so the BLED can take into account this press
            }
            break;
    }
    return pressed;
}
