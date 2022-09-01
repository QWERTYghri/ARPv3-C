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
	lnk -> mem[addr] = data;
}

int8_t read ( Bus* lnk, uint16_t addr )
{
        return lnk -> mem[addr];
}
