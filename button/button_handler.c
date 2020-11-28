#include "inttypes.h"
#include "button.h"



void ButtonInit(void){

  ButInit(BUTTON0_PORT,
          BUTTON0_PIN,
          BUTTON1_PORT,
          BUTTON1_PIN);
}


uint32_t ButtonPressedState(void){

  return BtnPressedState();
}
