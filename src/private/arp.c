/*
 *	C File for arp.h
 *	
 *	Contains program data for arp
 */

#include <stdlib.h>
#include "../public/arp.h"

Arp*
newArp ( uint16_t pc )
{
	Arp* obj = calloc ( 1, sizeof ( Arp ) );
	
	if ( obj == NULL )
		return NULL;
	
	obj -> pc = pc;	
	
	return obj;
}

void
delArp ( Arp* obj )
{
	free ( obj );
}
