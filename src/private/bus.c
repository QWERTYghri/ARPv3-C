/*
 * Bus.h header for cpu writes to bus and more
 */

#include <stdint.h>
#include <stdlib.h>
#include "../public/bus.h"

void Write ( Bus* lnk, uint16_t addr, int8_t data)
{
	if ( addr <= 0x1FFF )
		lnk -> cBus[addr] = data;
	else if ( addr > 0x1FFF && addr <= 0x3FFF )
		lnk -> sBus[addr] = data;
}

int8_t Read ( Bus* lnk, uint16_t addr )
{
	if ( addr <= 0x1FFF )
		return lnk -> cBus[addr];
	else if ( addr > 0x1FFF && addr <= 0x3FFF )
		return lnk -> sBus[addr];
		
	return 0;
}

Bus* setMem ( void )
{
	Bus* ptr = calloc ( 1, sizeof ( Bus ) );
	return ptr;
}
