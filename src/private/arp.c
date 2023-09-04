/*
 *	C File for arp.h
 *	
 *	Contains program data for arp
 */

#include <string.h>
#include <stdlib.h>

#include "../public/arp.h"

/* Constructors */
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


/* read write data */
void
writeByte ( Arp* obj, uint8_t value )
{
	obj -> memory -> memGroup[obj -> pc] = value;
	obj -> pc++;
}

void
writeWord ( Arp* obj, uint16_t value )
{
	/* Remove high 8 bits */
	obj -> memory -> memGroup[obj -> pc] = ( uint8_t ) ( value & 0xFF );
	obj -> pc++;
	
	obj -> memory -> memGroup[obj -> pc] = ( uint8_t ) ( value >> 8 );
	obj -> pc++;
}

uint8_t
readByte ( Arp* obj )
{
	uint8_t data = obj -> memory -> memGroup[obj -> pc];
	obj -> pc++;
	
	return data;
}

uint16_t
readWord ( Arp* obj )
{
	/* Get two bytes to merge into a word to return */
	uint8_t low	= readByte ( obj );
	uint8_t high	= readByte ( obj );
	
	return low | ( high << 8 );
}

/* Methods */
void
reset ( Arp* obj )
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

#include <stdio.h>

/* Find a way to separate the 3 bits in the CIR instruction
 *
 * Then find a way to not repeat code while still using the branches to
 * create a path for fetch memory data or register data
 */
void
addressData ( Arp* obj )
{
	if ( obj -> cir >> 7 != 0 )
	{
		switch ()
		{
			case IMPLIED:
			
				break;
			case IMMEDIATE:
				
				break;
			case DIRECT:
			
				break;
			case REGISTER_DIR:
			
				break;
			case REGISTER_DIR:
			
				break;
			default:
				break;
		}
	}
}

void
simulate ( Arp* obj, uint32_t cycles )
{
	while ( cycles > 0 )
	{
		obj -> cir = readByte ( obj );
		addressData ( obj );
	}
}
