/*
 * myGPIO.h
 *
 *  Created on:
 *      Author: Raymond Daniels (skeleton code provided by Dr. Thweatt)
 *
 */

#ifndef MYGPIO_H_
#define MYGPIO_H_

// This function initializes the peripherals used in the program.
void initGPIO();
// This function returns the value of Launchpad S1.
unsigned char checkStatus_LaunchpadS1();
// This function returns the value of Launchpad S2.
unsigned char checkStatus_LaunchpadS2();
// This function returns the value of Boosterpack S1.
unsigned char checkStatus_BoosterpackS1();
// This function returns the value of Boosterpack S2.
unsigned char checkStatus_BoosterpackS2();
// This function turns on Launchpad LED1.
void turnOn_LaunchpadLED1();
// This function turns off Launchpad LED1.
void turnOff_LaunchpadLED1();
// This function turns on Launchpad Red LED2.
void turnOn_LaunchpadLED2Red();
// This function turns off Launchpad Red LED2.
void turnOff_LaunchpadLED2Red();
// This function turns on Launchpad Blue LED2.
void turnOn_LaunchpadLED2Blue();
// This function turns off Launchpad Blue LED2.
void turnOff_LaunchpadLED2Blue();
// This function turns on Launchpad Green LED2.
void turnOn_LaunchpadLED2Green();
// This function turns off Launchpad Green LED2.
void turnOff_LaunchpadLED2Green();
// This function turns on Boosterpack Red LED.
void turnOn_BoosterpackLEDRed();
// This function turns off Boosterpack Red LED.
void turnOff_BoosterpackLEDRed();
// This function turns on Boosterpack Green LED.
void turnOn_BoosterpackLEDGreen();
// This function turns off Boosterpack Green LED.
void turnOff_BoosterpackLEDGreen();
// This function turns on Boosterpack Blue LED.
void turnOn_BoosterpackLEDBlue();
// This function turns off Boosterpack Blue LED.
void turnOff_BoosterpackLEDBlue();

// TODO: Define any constants that are local to myGPIO.c using #define
#define LED1 BIT0

#define redLED2 BIT0

#define greLED2 BIT1

#define bluLED2 BIT2

#define bluBLED BIT6

#define greBLED BIT4

#define redBLED BIT6

#define L1 BIT1

#define L2 BIT4

#define B1 BIT1

#define B2 BIT5

#define Port1 GPIO_PORT_P1

#define Port2 GPIO_PORT_P2

#define Port5 GPIO_PORT_P5

#define Port3 GPIO_PORT_P3

#define PIN0 GPIO_PIN0
#define PIN1 GPIO_PIN1
#define PIN2 GPIO_PIN2
#define PIN3 GPIO_PIN3
#define PIN4 GPIO_PIN4
#define PIN5 GPIO_PIN5
#define PIN6 GPIO_PIN6
#define PIN7 GPIO_PIN7
#define PIN8 GPIO_PIN8
#define PIN9 GPIO_PIN9
#define PIN10 GPIO_PIN10
#define PIN11 GPIO_PIN11
#define PIN12 GPIO_PIN12
#define PIN13 GPIO_PIN13
#define PIN14 GPIO_PIN14
#define PIN15 GPIO_PIN15

#endif /* MYGPIO_H_ */
