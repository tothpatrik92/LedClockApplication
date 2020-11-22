/*
 * led_control.c
 *
 *  Created on: Nov 22, 2020
 *      Author: patrik
 */
#include "inttypes.h"
#include "app.h"
#include "led.h"
#include "em_gpio.h"
#include "assert.h"
#include "debug.h"

/*
 * X    X   :   X   X
 * 0    1   2   3   4
 */
static uint8_t n;




void LeDriveSegments(APP_TIME time){


  LeDriveSegment(time);
  DebugPrint("\n%d%d:%d%dseg:%d\n",time.h1,time.h0,time.m1,time.m0,n);


}

void LeDriveSegment(APP_TIME time){


  LeDriveMux();
  LeDriveSevenSeg(time);
  n++;
  if((LED_NUM_OF_SEGMENTS-1) < n){
      n=0;
  }
}
void LeDriveMux(){

  switch(n){
    case 0:
      CLR(MUX_PORT_4051,MUX_PIN_A);
      CLR(MUX_PORT_4051,MUX_PIN_B);
      CLR(MUX_PORT_4051,MUX_PIN_C);
      break;
    case 1:
      SET(MUX_PORT_4051,MUX_PIN_A);
      CLR(MUX_PORT_4051,MUX_PIN_B);
      CLR(MUX_PORT_4051,MUX_PIN_C);
      break;
    case 2:
      CLR(MUX_PORT_4051,MUX_PIN_A);
      SET(MUX_PORT_4051,MUX_PIN_B);
      CLR(MUX_PORT_4051,MUX_PIN_C);
      break;
    case 3:
      SET(MUX_PORT_4051,MUX_PIN_A);
      SET(MUX_PORT_4051,MUX_PIN_B);
      CLR(MUX_PORT_4051,MUX_PIN_C);
      break;
    case 4:
      CLR(MUX_PORT_4051,MUX_PIN_A);
      CLR(MUX_PORT_4051,MUX_PIN_B);
      SET(MUX_PORT_4051,MUX_PIN_C);
      break;

  }

}

void LeDriveSevenSeg(APP_TIME time){


  uint8_t number;
  if(0 == n){
      //h1
      number=time.h1;

  }else if(1 == n){
      //h0
      number=time.h0;

  }else if(2 == n){
      //Here we do nothing since it's the dot

  }else if(3 == n){
      //m1
      number=time.m1;

  }else if(4 == n){
      //m0
      number=time.m0;
  }
  else{
      DebugPrint("Invaild number of segment. Must be 0 to 4");
      assert(0);
  }

  switch(number){
    case 0:
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_A);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_B);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_C);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_D);
      break;
    case 1:
      SET(SEVENSEG_PORT,SEVENSEG_PIN_A);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_B);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_C);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_D);
      break;
    case 2:
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_A);
      SET(SEVENSEG_PORT,SEVENSEG_PIN_B);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_C);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_D);
      break;
    case 3:
      SET(SEVENSEG_PORT,SEVENSEG_PIN_A);
      SET(SEVENSEG_PORT,SEVENSEG_PIN_B);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_C);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_D);
      break;
    case 4:
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_A);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_B);
      SET(SEVENSEG_PORT,SEVENSEG_PIN_C);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_D);
      break;
    case 5:
      SET(SEVENSEG_PORT,SEVENSEG_PIN_A);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_B);
      SET(SEVENSEG_PORT,SEVENSEG_PIN_C);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_D);
      break;
    case 6:
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_A);
      SET(SEVENSEG_PORT,SEVENSEG_PIN_B);
      SET(SEVENSEG_PORT,SEVENSEG_PIN_C);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_D);
      break;
    case 7:
      SET(SEVENSEG_PORT,SEVENSEG_PIN_A);
      SET(SEVENSEG_PORT,SEVENSEG_PIN_B);
      SET(SEVENSEG_PORT,SEVENSEG_PIN_C);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_D);
      break;
    case 8:
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_A);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_B);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_C);
      SET(SEVENSEG_PORT,SEVENSEG_PIN_D);
      break;
    case 9:
      SET(SEVENSEG_PORT,SEVENSEG_PIN_A);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_B);
      CLR(SEVENSEG_PORT,SEVENSEG_PIN_C);
      SET(SEVENSEG_PORT,SEVENSEG_PIN_D);
      break;
  }


}
