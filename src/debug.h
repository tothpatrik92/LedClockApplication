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
#define DebugPrint(...) printf(__VA_ARGS__)
#else
#define DebugPrint(a)
#endif

#endif /* SRC_DEBUG_H_ */

