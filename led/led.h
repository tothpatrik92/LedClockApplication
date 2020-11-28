/*
 * led_handler.h
 *
 *  Created on: Nov 22, 2020
 *      Author: patrik
 */

#ifndef SRC_LED_H_
#define SRC_LED_H_
#include "inttypes.h"
#include "app.h"


#define LED_NUM_OF_SEGMENTS 5

#define SET(a,b) GPIO_PinOutSet(a,b)
#define CLR(a,b) GPIO_PinOutClear(a,b)


#define MUX_PORT_4051 gpioPortF
#define MUX_PIN_A 5
#define MUX_PIN_B 6
#define MUX_PIN_C 7

#define SEVENSEG_PORT gpioPortA
#define SEVENSEG_PIN_A 8
#define SEVENSEG_PIN_B 9
#define SEVENSEG_PIN_C 6
#define SEVENSEG_PIN_D 7


void LedInit(void);
void LedDrive(APP_TIME ClockTime);
void LeDriveSegments(APP_TIME ClockTime);
void LeDriveSegment(APP_TIME ClockTime);
void LeDriveMux();
void LeDriveSevenSeg(APP_TIME ClockTime);
void LeInitGPIO(void);


#endif /* SRC_LED_H_ */
