/*
 * C file for bus.h
 *
 * Holds functions for bus.h
 */

#include <stdlib.h>

#include "../public/bus.h"

Bus*
newBus ( uint16_t maxMem )
{
	Bus* memObj = calloc ( 1, sizeof ( Bus ) );
	
	if ( memObj == NULL )
		return NULL;
	
	/* Allocate bytes for memory
	   No need to compare for MAXADDR, uint16_t already maxed */
	if ( maxMem > 0 )
		memObj -> memGroup = calloc ( maxMem, sizeof ( uint8_t ) );
	
	return memObj;
}

void
delBus ( Bus* obj )
{
	free ( obj );
}
