#include "em_timer.h"
#include "em_cmu.h"
#include "debug.h"

volatile uint32_t msTicks = 0;

void EvInitTimer(uint32_t tickPeriod){

  uint32_t setTick;
  setTick=(CMU_ClockFreqGet(cmuClock_CORE) / 1000) * tickPeriod;
  DebugPrint("Desired period: %d ms\n",tickPeriod);
  if(setTick>0xFFFFFF){
      setTick=0xFFFFFF;
      DebugPrint("Systick period is too long. Max value is 0xffffff, ~2.2Hz");
  }
  SysTick_Config(setTick);
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
