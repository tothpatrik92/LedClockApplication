/*
 * app.c
 *
 *  Created on: Nov 22, 2020
 *      Author: patrik
 */

#include "app.h"
#include "event.h"
#include "led.h"
#include "debug.h"
#include "button.h"
#include "em_rtcc.h"
#include "inttypes.h"

void AppMain(void){

  APP_EVENT event;

  APP_TIME time_hhmm;


  while(1){

  event=EventGetAppState();
  time_hhmm=AppGetTime();

  switch (event){

    case app_event_timer_set:
      NVIC_DisableIRQ(GPIO_EVEN_IRQn);
      NVIC_DisableIRQ(GPIO_ODD_IRQn);
      uint8_t btnCnt=0,dig=0;
      while(GPIO_PinInGet(BUTTON0_PORT, BUTTON0_PIN) &&
          4>dig){ //wait for a button0 press

          while(GPIO_PinInGet(BUTTON1_PORT, BUTTON1_PIN)){
              if(!GPIO_PinInGet(BUTTON0_PORT, BUTTON0_PIN)){

                  if(0==dig){
                      RTCC->TIME=0;
                      RTCC->TIME|=(btnCnt<<_RTCC_TIME_HOURT_SHIFT);

                  }else if(1==dig){
                      RTCC->TIME|=(btnCnt<<_RTCC_TIME_HOURU_SHIFT);

                  }else if(2==dig){
                      RTCC->TIME|=(btnCnt<<_RTCC_TIME_MINT_SHIFT);

                  }else if(3==dig){
                      RTCC->TIME|=(btnCnt<<_RTCC_TIME_MINU_SHIFT);
                  }

                  dig++;
                  while(!GPIO_PinInGet(BUTTON0_PORT, BUTTON0_PIN));
                  btnCnt=0;

                  if(4==dig){
                      break;
                  }
              }
          }
          btnCnt++;
          while(!GPIO_PinInGet(BUTTON1_PORT, BUTTON1_PIN));
      }
      dig=0;
      NVIC_EnableIRQ(GPIO_EVEN_IRQn);
      NVIC_EnableIRQ(GPIO_ODD_IRQn);

      break;
    case app_event_timer_show:
      LedDrive(time_hhmm);
      break;
    case app_event_illum_get:
      break;
    case app_event_illum_set:
      break;
    case app_event_idle:

      break;
  }

  }


}

APP_TIME AppGetTime(void){

  APP_TIME tmpTime;
  tmpTime.m0=(RTCC->TIME&_RTCC_TIME_MINU_MASK)>>_RTCC_TIME_MINU_SHIFT;
  tmpTime.m1=(RTCC->TIME&_RTCC_TIME_MINT_MASK)>>_RTCC_TIME_MINT_SHIFT;
  tmpTime.h0=(RTCC->TIME&_RTCC_TIME_HOURU_MASK)>>_RTCC_TIME_HOURU_SHIFT;
  tmpTime.h1=(RTCC->TIME&_RTCC_TIME_HOURT_MASK)>>_RTCC_TIME_HOURT_SHIFT;

  return tmpTime;
}
