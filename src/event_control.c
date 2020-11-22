#include "em_timer.h"
#include "em_cmu.h"

volatile uint32_t msTicks = 0;

void EvInitTimer(uint32_t tickPeriod){


  SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000);
  uint32_t tmp=CMU_ClockFreqGet(cmuClock_CORE) / 1000;

}


void SysTick_Handler(void){
  msTicks++;
  //if(msTicks>1000){
  //    msTicks=0;
  //}
}

uint32_t EvGetCurrTick(void){

  return msTicks;
}
