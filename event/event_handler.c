/*
 * event_handler.c
 *
 *  Created on: Nov 22, 2020
 *      Author: patrik
 */
#include "event.h"
#include "debug.h"
#include "app.h"

static uint32_t currTick;
static uint32_t prevTick;








void EventInit(uint32_t tickPeriod){


  EvInitTimer(tickPeriod);

}

EVENT EventGetAppState(void){

  EVENT ret=event_idle;

  prevTick=currTick;
  currTick=EvGetCurrTick();

  //if 1ms is elapsed, perform LED refreshing
  if(currTick!=prevTick){
      ret=event_timer_show;
      DebugPrint("ret=event_timer_show;");
  }

  return ret;

}
APP_TIME EventGetTime(void){

  APP_TIME tmp;
  return tmp;
}
