#include "em_timer.h"
#include "em_cmu.h"
#include "debug.h"
#include "event.h"
#include "app.h"

volatile uint32_t msTicks = 0;
volatile uint32_t secTicks = 0;

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

extern uint8_t startReEnableTimer;
uint32_t startReEnableCounter=0;
//#define RTCC_TEST
static uint32_t sample[100][2];
static uint8_t rtcc_test_cnt_sor;
extern uint32_t restore;
void SysTick_Handler(void){
#ifdef RTCC_TEST
  if(rtcc_test_cnt_sor==0){RTCC->TIME=0;RTCC->PRECNT=0;}
  if((msTicks>100)&&(rtcc_test_cnt_sor<100)){
  sample[rtcc_test_cnt_sor][0]=RTCC->PRECNT;
  sample[rtcc_test_cnt_sor][1]=(RTCC->TIME&_RTCC_TIME_SECT_MASK)>>_RTCC_TIME_SECT_SHIFT;
      rtcc_test_cnt_sor++;
      msTicks=0;
  }

  msTicks++;

#else
  msTicks++;
  if(msTicks>1000){
      msTicks=0;
      secTicks++;
  }
  if(startReEnableTimer==1){
      startReEnableCounter++;
      if(startReEnableCounter==200){
          startReEnableTimer=0;
          startReEnableCounter=0;
          GPIO->IFC=0x7f;
          //GPIO->IEN=restore;
          __NVIC_EnableIRQ(GPIO_EVEN_IRQn);
          __NVIC_EnableIRQ(GPIO_ODD_IRQn);
      }
  }
#endif
}

uint32_t EvGetCurrTick(void){

  return msTicks;
}


