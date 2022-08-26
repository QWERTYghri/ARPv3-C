/*
 * Bus.h header for cpu writes to bus and more
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../public/bus.h"

/* Implement soon */
void write ( Bus* lnk, uint16_t addr, int8_t data )
{

}

int8_t read ( Bus* lnk, uint16_t addr )
{

}

Bus* setMem ( uint16_t busSec, ... )
{
	Bus* setBus = calloc ( 1, sizeof ( Bus ) );
	
	va_list cBus;
	int32_t mCnt = 0;
	
	while ( mCnt <= MAXADDR )
	{
	
	}
	
	va_end ( cBus );
	
	return setBus;
}
