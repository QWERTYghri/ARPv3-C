/*
 * Bus.h header for cpu writes to bus and more
 */

#ifndef BUS_H
#define BUS_H

#include <stdint.h>

typedef struct Bus
{
	int8_t cBus[0x1FFF];
	int8_t sBus[0x2000];
} Bus;

void Write ( Bus* lnk, uint16_t addr, int8_t data);
int8_t Read ( Bus* lnk, uint16_t addr );

#endif /* End */
