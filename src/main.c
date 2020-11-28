#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include "em_emu.h"
#include "app.h"
#include "event.h"
#include "led.h"
#include "button.h"
#include "illum.h"
#include "retargetserial.h"
#include "debug.h"
#include "assert.h"

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

  /* Infinite loop */
  while (1) {

      AppMain();
      //never reach this point
      assert(0);
  }
}

