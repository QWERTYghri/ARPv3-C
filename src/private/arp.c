/*
 *	C File for arp.h
 *	
 *	Contains program data for arp
 */

#include <string.h>
#include <stdlib.h>

#include "../public/arp.h"

Arp*
newArp ( uint16_t pc, Bus* memObj )
{
	Arp* obj = calloc ( 1, sizeof ( Arp ) );
	
	if ( obj == NULL )
		return NULL;
	
	obj -> pc = pc;
	obj -> memory = memObj;
	
	return obj;
}

void
delArp ( Arp* obj )
{
	free ( obj );
}

/* Methods */

void reset ( Arp* obj )
{
	/* Clear GP registers */
	obj -> r0 = obj -> r1 = obj -> r2 = obj -> r3 = 0;
	
	/* Clear PC register */
	obj -> pc = 0;
	
	/* Clear flags */
	memset ( &obj -> Flag, 0, sizeof ( obj -> Flag ) );
	
	/* clean memory */
	for ( uint32_t i = 0; i <= MAXADDR; i++ )
		obj -> memory -> memGroup[i] = 0;
}
