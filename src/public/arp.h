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
			sbp,
			mbr;
			
	uint8_t		cir,
			mba;
	
	Bus*		memory;
	
	struct Flag
	{
		uint8_t	Z : 1,
			N : 1,
			V : 1,
			cmp : 3;
	} Flag;
} Arp;

Arp* newArp ( uint16_t pc, Bus* obj );
void delArp ( Arp* obj );

#endif /* END */
