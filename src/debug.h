/*
 * debug.h
 *
 *  Created on: Nov 22, 2020
 *      Author: patrik
 */

#ifndef SRC_DEBUG_H_
#define SRC_DEBUG_H_
#include "stdio.h"

#define DEBUG 1

#if DEBUG
#define DebugPrint(a) printf(a)
#else
#define DebugPrint(a)
#endif

#endif /* SRC_DEBUG_H_ */
