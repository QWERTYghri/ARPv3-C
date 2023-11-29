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
	uint8_t* memGroup;
	uint8_t ioPort[MAXPORT];
	
	uint64_t maxAddress;
} Bus;

Bus*	newBus ( uint16_t maxMem );
void	delBus ( Bus* obj );

#endif /* END */
