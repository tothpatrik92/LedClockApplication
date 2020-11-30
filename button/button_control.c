/*
 * button_control.c
 *
 *  Created on: Nov 22, 2020
 *      Author: patrik
 */
#include "stdbool.h"
#include "inttypes.h"
#include "button.h"
#include "app.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "debug.h"

volatile static uint32_t IntFlag;
static uint32_t CopyIntFlag;

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
  CopyIntFlag=IntFlag;
  while(!GPIO_PinInGet(BUTTON0_PORT, BUTTON0_PIN));
  GPIO_IntClear(IntFlag);
}

/**************************************************************************//**
 * @brief GPIO Odd IRQ for pushbuttons on odd-numbered pins
 *****************************************************************************/
void GPIO_ODD_IRQHandler(void)
{
  IntFlag=GPIO_IntGet();
  CopyIntFlag=IntFlag;
  while(!GPIO_PinInGet(BUTTON1_PORT, BUTTON1_PIN));
  GPIO_IntClear(IntFlag);
}

uint32_t BtnPressedState(void){

  uint32_t ret=IntFlag;
  IntFlag=0;
  return ret;
}

uint8_t BtnSetDigit(BUTTON_DIGIT state){

      return IncrementDigit(state);

}
int8_t GetPressedButton(void){
  __NVIC_DisableIRQ(GPIO_EVEN_IRQn);
  __NVIC_DisableIRQ(GPIO_ODD_IRQn);
  int8_t ret;
  if(0x4000==CopyIntFlag){
      CopyIntFlag=0;
      ret= 0;//button0
  }else if(0x8000==CopyIntFlag){
      CopyIntFlag=0;
      ret= 1;//button1
  }else{
      CopyIntFlag=0;
      ret= -1;
  }

  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);
  return ret;

}
uint8_t IncrementDigit(BUTTON_DIGIT state){

  uint8_t currentValue;
  switch(state){
    case digit0_InProgress:
      currentValue=(((RTCC->TIME)&_RTCC_TIME_HOURT_MASK)>>_RTCC_TIME_HOURT_SHIFT);
      RTCC->TIME=((RTCC->TIME)&(~_RTCC_TIME_HOURT_MASK));
      currentValue++;
      if(currentValue>2)currentValue=0;
      RTCC->TIME|=(currentValue<<_RTCC_TIME_HOURT_SHIFT);
      break;
    case digit1_InProgress:
      currentValue=(((RTCC->TIME)&_RTCC_TIME_HOURU_MASK)>>_RTCC_TIME_HOURU_SHIFT);
      RTCC->TIME=((RTCC->TIME)&(~_RTCC_TIME_HOURU_MASK));
      currentValue++;
      if(currentValue>9)currentValue=0;
      RTCC->TIME|=(currentValue<<_RTCC_TIME_HOURU_SHIFT);
      break;
    case digit2_InProgress:
      currentValue=(((RTCC->TIME)&_RTCC_TIME_MINT_MASK)>>_RTCC_TIME_MINT_SHIFT);
      RTCC->TIME=((RTCC->TIME)&(~_RTCC_TIME_MINT_MASK));
      currentValue++;
      if(currentValue>5)currentValue=0;
      RTCC->TIME|=(currentValue<<_RTCC_TIME_MINT_SHIFT);
      break;
    case digit3_InProgress:
      currentValue=(((RTCC->TIME)&_RTCC_TIME_MINU_MASK)>>_RTCC_TIME_MINU_SHIFT);
      RTCC->TIME=((RTCC->TIME)&(~_RTCC_TIME_MINU_MASK));
      currentValue++;
      if(currentValue>9)currentValue=0;
      RTCC->TIME|=(currentValue<<_RTCC_TIME_MINU_SHIFT);
      break;
  }


  BtnShowNumber(state,currentValue);
  return currentValue;

}
void BtnShowNumber(uint8_t digit,uint8_t value){
  if(2<=digit){
      //need to increment to skip the DOT LEDs since it's the 2nd segment
      LeDriveMux(digit+1);
  }else{
      LeDriveMux(digit);
  }
  LeSetLedDirect(value);

}
void BtnClearBntState(void){
  CopyIntFlag=0;
  IntFlag=0;
}
void BtnResetSec(void){

  RTCC->TIME=((RTCC->TIME)&(~_RTCC_TIME_SECT_MASK));
  RTCC->TIME=((RTCC->TIME)&(~_RTCC_TIME_SECU_MASK));
}
