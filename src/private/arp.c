/* ARP.c
 *
 * C file for arp.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../public/arp.h"
#include "../public/bus.h"


Arp* newArp ( uint16_t PC, Bus* busArg )
{
        Bus* mem;

        if ( busArg == NULL )
                mem = 

