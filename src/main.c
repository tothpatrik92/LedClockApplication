#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "em_emu.h"
#include "em_rtcc.h"
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
  EMU_DCDCInit(&dcdcInit);
  // Start the HFXO with safe default parameters
  CMU_HFXOInit_TypeDef hfxoInit = CMU_HFXOINIT_DEFAULT;
  CMU_HFXOInit(&hfxoInit);
  CMU_OscillatorEnable(cmuOsc_HFXO, true, true);

  // Switch the HFCLK to the HFXO.
  CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);

  RETARGET_SerialInit();
  RETARGET_SerialCrLf(1);

  EventInit(APP_PERIOD_MS);
  LedInit();
  ButtonInit();
  IllumInit();

  char hour_time[] = "132654";
  char *hour = &hour_time;//setCurrentTime(hour_time);
  int start_time = (int)strtol(hour,NULL,16);
  rtccSetup(start_time);

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
  rtcc.enable   = false;
  rtcc.presc = rtccCntPresc_32768;
  rtcc.cntMode = rtccCntModeCalendar;
  rtcc.cntWrapOnCCV1 = true;

  // Configure the compare settings
  RTCC_CCChConf_TypeDef compare = RTCC_CH_INIT_COMPARE_DEFAULT;

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
