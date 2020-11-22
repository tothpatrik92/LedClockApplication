/*
 * app.h
 *
 *  Created on: Nov 22, 2020
 *      Author: patrik
 */

#ifndef SRC_APP_H_
#define SRC_APP_H_

#include "inttypes.h"

// APP macros
#define APP_PERIOD_MS 1UL







typedef enum{
  app_event_timer_set   =0,
  app_event_timer_show  =1,
  app_event_illum_get   =2,
  app_event_illum_set   =3,
  app_event_idle        =4
}APP_EVENT;

typedef struct{
  uint8_t h1;
  uint8_t h0;
  uint8_t m1;
  uint8_t m0;
}APP_TIME;


void AppMain(void);
APP_TIME AppGetTime(void);

#endif /* SRC_APP_H_ */
