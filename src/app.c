/*
 * app.c
 *
 *  Created on: Nov 22, 2020
 *      Author: patrik
 */

#include "app.h"
#include "event.h"
#include "led.h"

void AppMain(void){

  APP_EVENT event;
  event=EventGetAppState();
  APP_TIME time_hhmm;
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

APP_TIME AppGetTime(void){

  APP_TIME dummy={1,2,3,8};
  return dummy;
}
