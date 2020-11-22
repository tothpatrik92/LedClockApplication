/*
 * event_handler.h
 *
 *  Created on: Nov 22, 2020
 *      Author: patrik
 */

#ifndef SRC_EVENT_H_
#define SRC_EVENT_H_

#include "inttypes.h"

typedef enum{
  event_timer_set   =0,
  event_timer_show  =1,
  event_illum_get   =2,
  event_illum_set   =3,
  event_idle        =4
}EVENT;




void EventInit(uint32_t tickPeriod);
EVENT EventGetAppState(void);
void EvInitTimer(uint32_t tickPeriod);
uint32_t EvGetCurrTick(void);


#endif /* SRC_EVENT_H_ */
