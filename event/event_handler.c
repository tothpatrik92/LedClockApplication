/*
 * event_handler.c
 *
 *  Created on: Nov 22, 2020
 *      Author: patrik
 */
#include "event.h"
#include "button.h"
#include "debug.h"
#include "app.h"

static uint32_t currTick;
static uint32_t prevTick;








void EventInit(uint32_t tickPeriod){


  EvInitTimer(tickPeriod);

}

EVENT EventGetAppState(void){

  EVENT ret;
  uint32_t eventBtn;

  prevTick=currTick;
  currTick=EvGetCurrTick();

  eventBtn=ButtonPressedState();
  if(0x1 == eventBtn){
      //button 0 is pressed
      ret=event_timer_set;
  }else if(currTick!=prevTick){
      ret=event_timer_show;
      //DebugPrint("ret=event_timer_show;");
  }else{

      ret=event_idle;
  }



  return ret;

}
APP_TIME EventGetTime(void){

  APP_TIME tmp;
  return tmp;
}

