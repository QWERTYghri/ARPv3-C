/*
 * ARPv3 main header
 * Contains CPU data struct
 */

#ifndef ARP_H
#define ARP_H

#include <stdlib.h>
#include <stdint.h>

#include "./bus.h"

typedef struct
{
	int16_t 	r0,
			r1,
			r2,
			r3;
	
	uint16_t	pc,
			sp,
			sbp;
			
	int16_t		mbr;
			
	int8_t		cir;
	
	Bus*		memory;
	
	struct Flag
	{
		uint8_t	Z : 1,
			N : 1,
			V : 1,
			cmp : 3;
	} Flag;
} Arp;

/* Address Modes */
enum {
	IMP,
	IMM,
	DIR
};

/* Constructors */
Arp* newArp ( uint16_t pc, Bus* obj );
void delArp ( Arp* obj );

/* Read Write */
void writeByte ( Arp* obj, uint16_t addr, int8_t value );
void writeWord ( Arp* obj, uint16_t addr, int16_t value );

int8_t readByte ( Arp* obj, uint16_t addr );
int16_t readWord ( Arp* obj, uint16_t addr );

/* Methods */
void reset ( Arp* obj );
void step ( Arp* obj );
void simulate ( Arp* obj, uint32_t cycles );

#endif /* END */
