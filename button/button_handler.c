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
void ButtonSetDigit(void){
  static BUTTON_DIGIT DigitState=digit0_InProgress;
  BtnClearBntState();
  int8_t button;
  uint8_t newValue;
  BtnShowNumber(DigitState,AppGetTimeDigit(DigitState));
  while(digit3_Done!=DigitState){

    button=GetPressedButton();
    if(button==0){
        DigitState++;
        BtnShowNumber(DigitState,AppGetTimeDigit(DigitState));
    }else if(button==1){
        newValue=BtnSetDigit(DigitState);
        BtnShowNumber(DigitState,newValue);
    }

  }
  DigitState=digit0_InProgress;
  BtnResetSec();
  BtnClearBntState();

}

