/*
 * Bus.h header for cpu writes to bus and more
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
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

Bus* setMem ( uint16_t busSec, ... )
{
	Bus* retBus = NULL;

	va_list sec;
	va_start ( sec, busSec );
	
	
	
	va_end ( sec );
}
