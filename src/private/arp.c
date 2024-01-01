/*
 *	C File for arp.h
 *	
 *	Contains program data for arp
 */

#include <string.h>
#include <stdlib.h>

#include "../public/arp.h"

/* Macros */
#define BW_BIT_SHIFT ( 7 )
#define AM_BIT_SHIFT ( 4 )

#define AM_BIT_CLEAR ( 0x70 )
#define OP_BIT_CLEAR ( 0xF )

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
writeByte ( Arp* obj, uint16_t addr, int8_t value )
{
	obj -> memory -> memGroup[addr] = value;
}

void
writeWord ( Arp* obj, uint16_t addr, int16_t value )
{
	/* Remove high 8 bits */
	obj -> memory -> memGroup[addr] = ( int8_t ) ( value & 0xFF );
	obj -> memory -> memGroup[addr + 1] = ( int8_t ) ( value >> 8 );
}

int8_t
readByte ( Arp* obj, uint16_t addr )
{
	uint8_t data = obj -> memory -> memGroup[addr];

	return data;
}

int16_t
readWord ( Arp* obj, uint16_t addr )
{
	/* Get two bytes to merge into a word to return */
	return readByte ( obj, addr ) | ( readByte ( obj, addr + 1 ) << 8 );
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
	for ( uint32_t i = 0; i <= obj -> memory -> maxAddress; i++ )
		obj -> memory -> memGroup[i] = 0;
}

#include <stdio.h>

/* Find a way to separate the 3 bits in the CIR instruction
 *
 * Then find a way to not repeat code while still using the branches to
 * create a path for fetch memory data or register data
 */
 
static int16_t
wordOrByteFetch ( Arp* obj )
{
	int16_t returnVal;

	printf ( "Word/byte: %d\n", obj -> cir >> BW_BIT_SHIFT );
	if ( obj -> cir >> BW_BIT_SHIFT ) {
		/* Return if the option is to read a word */
		returnVal = readWord ( obj, ++obj -> pc );
		obj -> pc += 2;
	} else {
		/* Return if the option is to read a byte */
		returnVal = readByte ( obj, ++obj -> pc );
		obj -> pc++;
	}
	
	return returnVal;
}

static void
assignRegister ( Arp* obj, int32_t reg )
{
	

	switch ( reg )
	{
		case 0:
			
			break;
		case 1:
		
			break;
		case 2:
		
			break;
		case 3:
		
			break;
	}
}

static void
addressModeFetch ( Arp* obj )
{
	/* Get data from address mode */
	printf ( "Address Mode: %d\n", ( obj -> cir & AM_BIT_CLEAR ) >> AM_BIT_SHIFT );
	
	switch ( ( obj -> cir & AM_BIT_CLEAR ) >> AM_BIT_SHIFT )
	{
		/* Memory based */
		case IMP:
			/* Do nothing */
			
			break;
		case IMM:
			obj -> mbr = wordOrByteFetch ( obj );
			
			break;
		case DIR:
			uint16_t address = ( uint16_t ) wordOrByteFetch ( obj );
			obj -> mbr = obj -> memory -> memGroup[address];

			break;
		case RIMM:
			
			break;
		case RDIR:
		
			break;
	}
}

static void
executeInstruction ( Arp* obj )
{
	printf ( "Opcode: %d\n", obj -> cir & OP_BIT_CLEAR );
	
	/* Get Opcode */
	switch ( obj -> cir & OP_BIT_CLEAR )
	{
		
	}
}

void
step ( Arp* obj )
{
 	/* Get current instruction */
 	printf ( "test\n" );
 	
	obj -> cir = obj -> memory -> memGroup[obj -> pc];	
	addressModeFetch ( obj );
	executeInstruction ( obj );
}

void
simulate ( Arp* obj, uint32_t cycles )
{
	while ( cycles > 0 )
	{
		step ( obj );
		cycles--;
	}
}
