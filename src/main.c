#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "em_emu.h"
#include "em_rtcc.h"
#include "em_timer.h"
#include "app.h"
#include "event.h"
#include "led.h"
#include "button.h"
#include "illum.h"
#include "retargetserial.h"
#include "debug.h"
#include "assert.h"

int start = -1;
void rtccSetup(int start_time);


int main(void)
{
  /* Chip errata */
  CHIP_Init();
  EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_DEFAULT;
  dcdcInit.powerConfig=emuDcdcMode_Bypass;
  EMU_DCDCInit(&dcdcInit);
  // Start the HFXO with safe default parameters
  CMU_HFXOInit_TypeDef hfxoInit = CMU_HFXOINIT_DEFAULT;
  hfxoInit.ctuneSteadyState=332;
  CMU_HFXOInit(&hfxoInit);
  CMU_OscillatorEnable(cmuOsc_HFXO, true, true);

  // Switch the HFCLK to the HFXO.
  CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);

  //initTimer();

  RETARGET_SerialInit();
  RETARGET_SerialCrLf(1);

  EventInit(APP_PERIOD_MS);
  LedInit();
  ButtonInit();
  IllumInit();

  char hour_time[] = "171700";
  char *hour = &hour_time;//setCurrentTime(hour_time);
  int start_time = (int)strtol(hour,NULL,16);
  rtccSetup(start_time);

  __NVIC_SetPriority(GPIO_ODD_IRQn, 0);
  __NVIC_SetPriority(GPIO_EVEN_IRQn, 1);
  __NVIC_SetPriority(SysTick_IRQn, 2);
  /* Infinite loop */
  while(1){

      AppMain();
      //never reach this point
      assert(0);
  }
}
void rtccSetup(int start_time)
{
  // Configure the RTCC settings
  RTCC_Init_TypeDef rtcc = RTCC_INIT_DEFAULT;
  //rtcc.enable   = false;
  rtcc.presc = rtccCntPresc_32768;
  rtcc.cntMode = rtccCntModeCalendar;
  //rtcc.cntWrapOnCCV1 = true;

  // Configure the compare settings
  //RTCC_CCChConf_TypeDef compare = RTCC_CH_INIT_COMPARE_DEFAULT;

  CMU_LFXOInit_TypeDef lfxoInit = CMU_LFXOINIT_DEFAULT;
  //https://www.silabs.com/community/mcu/32-bit/knowledge-base.entry.html/2017/09/01/clfxo_ts_parametera-Fcrq
  //TUNING = ((desiredTotalLoadCap × 2 - Min(CLFXO_T)) / SSLFXO)
  //TUNING = ((12                   × 2 -       8)      / 0.25)
  lfxoInit.ctune=0x49; //73 dec
  CMU_LFXOInit(&lfxoInit);
  CMU_OscillatorEnable(cmuOsc_LFXO, true, true);

  // Turn on the clock for the RTCC
  CMU_ClockEnable(cmuClock_HFLE, true);
  CMU_ClockSelectSet(cmuClock_LFE, cmuSelect_LFXO);
  CMU_ClockEnable(cmuClock_RTCC, true);

  // Initialise RTCC with pre-defined settings
  RTCC_Init(&rtcc);

  // Set current time
  RTCC_TimeSet(start_time);

  // Start counter after all initialisations are complete
  RTCC_Enable(true);
}
void initTimer(void)
{
  // Enable clock for TIMER0 module
  CMU_ClockEnable(cmuClock_TIMER0, true);

  // Configure TIMER0 Compare/Capture for output compare
  TIMER_InitCC_TypeDef timerCCInit = TIMER_INITCC_DEFAULT;
  timerCCInit.mode = timerCCModeCompare;
  timerCCInit.cmoa = timerOutputActionSet;
  TIMER_InitCC(TIMER0, 0, &timerCCInit);

  // Set route to Location 15 and enable
  // TIM0_CC0 #15 is P10


  // Set compare value for 3 second delay
  uint32_t compareValue =5000;
  TIMER_CompareSet(TIMER0, 0, compareValue);
  TIMER_TopSet(TIMER0, 10000);

  // Initialize and start timer with defined prescale
  TIMER_Init_TypeDef timerInit = TIMER_INIT_DEFAULT;
  timerInit.prescale = timerPrescale32;
  TIMER_Init(TIMER0, &timerInit);
  TIMER_IntEnable(TIMER0, TIMER_IEN_CC0|TIMER_IEN_OF);
  NVIC_EnableIRQ(TIMER0_IRQn);

}
volatile uint32_t ff;
void TIMER0_IRQHandler(void)
{
  static uint32_t i = 0;

  // Acknowledge the interrupt
  uint32_t flags = TIMER_IntGet(TIMER0);
  TIMER_IntClear(TIMER0, flags);

  // Check for capture event on channel 0
  if (flags & TIMER_IF_CC0) {
      GPIO_PinOutSet(MUX_PORT_4051, MUX_PIN_A);
      GPIO_PinOutSet(MUX_PORT_4051, MUX_PIN_B);
      GPIO_PinOutSet(MUX_PORT_4051, MUX_PIN_C);
  }else if(flags & TIMER_IF_OF){
      GPIO_PinOutClear(MUX_PORT_4051, MUX_PIN_A);
      GPIO_PinOutClear(MUX_PORT_4051, MUX_PIN_B);
      GPIO_PinOutClear(MUX_PORT_4051, MUX_PIN_C);
  }
}
