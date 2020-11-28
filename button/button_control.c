/*
 * button_control.c
 *
 *  Created on: Nov 22, 2020
 *      Author: patrik
 */
#include "stdbool.h"
#include "inttypes.h"
#include "button.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "debug.h"

volatile static uint32_t IntFlag;
void ButInit(uint8_t button0Port,
                uint8_t button0Pin,
                uint8_t button1Port,
                uint8_t button1Pin){


  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(button0Port, button0Pin, gpioModeInput, 0);
  GPIO_PinModeSet(button1Port, button1Pin, gpioModeInput, 0);

  // Enable IRQ for even numbered GPIO pins
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);

  // Enable IRQ for odd numbered GPIO pins
  NVIC_EnableIRQ(GPIO_ODD_IRQn);

  // Enable falling-edge interrupts for PB pins
  GPIO_ExtIntConfig(button0Port, button0Pin, BUTTON0_INT_NUM, 0, 1, true);
  GPIO_ExtIntConfig(button1Port, button1Pin, BUTTON1_INT_NUM, 0, 1, true);

}

void GPIO_EVEN_IRQHandler(void)
{
  // Clear all even pin interrupt flags
  IntFlag=GPIO_IntGet();

  while(!GPIO_PinInGet(BUTTON0_PORT, BUTTON0_PIN));
  GPIO_IntClear(IntFlag);
}

/**************************************************************************//**
 * @brief GPIO Odd IRQ for pushbuttons on odd-numbered pins
 *****************************************************************************/
void GPIO_ODD_IRQHandler(void)
{
  IntFlag=GPIO_IntGet();
  while(!GPIO_PinInGet(BUTTON1_PORT, BUTTON1_PIN));
  GPIO_IntClear(IntFlag);
}

uint32_t BtnPressedState(void){

  uint32_t ret=IntFlag;
  IntFlag=0;
  return ret;
}



