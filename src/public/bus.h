/*
 * Bus file
 *
 * Used to segment the CPU's address bus
 */
 
#ifndef BUS_H
#define BUS_H

#include <stdint.h>
#include "./define.h"

typedef struct
{
	int8_t* memGroup;
	int8_t ioPort[MAXPORT];
} Bus;

Bus*	newBus ( uint16_t maxMem );
void	delBus ( Bus* obj );

#endif /* END */
