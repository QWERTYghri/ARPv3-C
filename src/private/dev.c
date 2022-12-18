/* Dev.c file
 *
 * file for devices and defining their
 * functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../public/arp.h"
#include "../public/bus.h"
#include "../public/dev.h"

Dev* newDev ( uint16_t devId,
              char* desc,
              void ( *tick ) ( Bus* lnk, Dev* ref ) )
{
        Dev* obj = calloc ( 0, sizeof ( Dev ) );
        
        obj -> devId = devId;
        snprintf ( obj -> desc, MAXDESC, "%s", desc );
        obj -> tick = tick;

        if ( rng1 > rng2 ) 
                return -1

        obj -> rng1 = rng1;
        obj -> rng2 = rng2

        return obj;
}

void stepDev ( Dev* lnk )
{

}

void delDev ( Dev* lnk ) {
        free ( lnk );
}
