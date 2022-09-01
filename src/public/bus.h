/*
 * Bus.h header for cpu writes to bus and more
 */

#ifndef BUS_H
#define BUS_H

#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAXADDR ( ( uint16_t ) 1024 * 64 )

typedef struct Bus
{
	int8_t mem[MAXADDR];
} Bus;

void write ( Bus* lnk, uint16_t addr, int8_t data );
int8_t read ( Bus* lnk, uint16_t addr );

#endif /* End */
