/*
 * button.h
 *
 *  Created on: Nov 22, 2020
 *      Author: patrik
 */
#include "inttypes.h"
#include "em_gpio.h"


#ifndef SRC_BUTTON_H_
#define SRC_BUTTON_H_

#define BUTTON0_PORT  gpioPortD
#define BUTTON0_PIN   14
#define BUTTON1_PORT  gpioPortD
#define BUTTON1_PIN   15

#define BUTTON0_INT_NUM BUTTON0_PIN
#define BUTTON1_INT_NUM BUTTON1_PIN

void ButtonInit(void);
void ButInit(uint8_t button0Port,
                uint8_t button0Pin,
                uint8_t button1Port,
                uint8_t button1Pin);
uint32_t ButtonPressedState(void);
uint32_t ButPressedState(void);

#endif /* SRC_BUTTON_H_ */
