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

#define BUTTON0_PORT  gpioPortK
#define BUTTON0_PIN   0
#define BUTTON1_PORT  gpioPortK
#define BUTTON1_PIN   2

#define BUTTON0_INT_NUM BUTTON0_PIN
#define BUTTON1_INT_NUM BUTTON1_PIN
typedef enum{
  digit0_InProgress=0,
  digit1_InProgress,
  digit2_InProgress,
  digit3_InProgress,
  digit3_Done,
}BUTTON_DIGIT;
void ButtonInit(void);
void ButInit(uint8_t button0Port,
                uint8_t button0Pin,
                uint8_t button1Port,
                uint8_t button1Pin);
uint32_t ButtonPressedState(void);
uint32_t ButPressedState(void);
void ButtonSetDigit(void);
int8_t GetPressedButton(void);
uint8_t IncrementDigit(BUTTON_DIGIT state);
void BtnShowNumber(uint8_t digit,uint8_t value);
void BtnClearBntState(void);
void BtnResetSec(void);

#endif /* SRC_BUTTON_H_ */
