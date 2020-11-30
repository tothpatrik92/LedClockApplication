
#include "led.h"
#include "app.h"








void LedInit(void){

  LeInitGPIO();
}

void LedDrive(APP_TIME ClockTime){

  LeDriveSegments(ClockTime);

}

