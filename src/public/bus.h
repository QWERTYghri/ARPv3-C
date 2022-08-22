/*
 * Bus.h header for cpu writes to bus and more
 */

#ifndef BUS_H
#define BUS_H

#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAXADDR ( ( uint16_t ) 0xffff )

typedef struct Bus
{
	int8_t* memSecs[MAXADDR];
} Bus;

void Write ( Bus* lnk, uint16_t addr, int8_t data);
int8_t Read ( Bus* lnk, uint16_t addr );
Bus* setMem ( uint16_t busSec, ... );

#endif /* End */
