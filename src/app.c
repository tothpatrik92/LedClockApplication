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
    case app_event_timer_set_done:
    case app_event_timer_set_ongoing:
      if(app_event_timer_set_done==event){
          event=app_event_timer_show;
      }else{
          ButtonSetDigit();
      }
      event=app_event_timer_show;
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

uint8_t AppGetTimeDigit(uint8_t digit){

  uint8_t ret;
  switch(digit){
    case 0:
      ret = ((RTCC->TIME&_RTCC_TIME_HOURT_MASK)>>_RTCC_TIME_HOURT_SHIFT);
      break;
    case 1:
      ret = ((RTCC->TIME&_RTCC_TIME_HOURU_MASK)>>_RTCC_TIME_HOURU_SHIFT);
      break;
    case 2:
      ret = ((RTCC->TIME&_RTCC_TIME_MINT_MASK)>>_RTCC_TIME_MINT_SHIFT);
      break;
    case 3:
      ret = ((RTCC->TIME&_RTCC_TIME_MINU_MASK)>>_RTCC_TIME_MINU_SHIFT);
      break;
    default:
      ret = 0;

      return ret;

  }

}
