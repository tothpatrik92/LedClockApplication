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

void AppMain(void){

  APP_EVENT event;

  APP_TIME time_hhmm;


  while(1){

  event=EventGetAppState();
  time_hhmm=AppGetTime();


  switch (event){
    case app_event_timer_set:
      break;
    case app_event_timer_show:
      LedDrive(time_hhmm);
      break;
    case app_event_illum_get:
      break;
    case app_event_illum_set:
      break;
    case app_event_idle:
      //em2
      break;
  }

  }


}

APP_TIME AppGetTime(void){

  APP_TIME dummy={1,2,3,8};
  return dummy;
}
