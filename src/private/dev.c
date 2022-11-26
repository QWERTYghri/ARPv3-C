/* Dev.c file
 *
 * file for devices and defining their
 * functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../public/dev.h"

Dev* newDev ( uint16_t devId,
              char* desc
              void ( *tick ) ( Arp* lnk, Dev* ref ) )
{
        Dev* obj = calloc ( 0, sizeof ( dev ) );
        
        obj -> devId = devId;
        snprintf ( obj -> desc, MAXDESC, "%s" desc );
        obj -> tick = tick;

        return obj;
}

void delDev ( Dev* lnk ) {
        free ( Dev );
}
