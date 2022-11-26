/*
 * dev.h
 *
 * Header for device programs
 */

#ifndef DEV_H
#define DEV_H

#include <stdlib.h>
#include <stdint.h>
#include "./bus.h"
#include "./arp.h"


/* Definitions */
#define MAXDESC ( 250 )

typedef struct {
        /* Preferable data */
        uint16_t devId;
        char* desc[MAXDESC];

        void (*tick) ( Arp* lnk, Dev* ref );
} Dev;

#ifdef __cplusplus
extern "C" {
#endif

Dev* newDev ( uint16_t devId,
              char* desc
              void ( *tick ) ( Arp* lnk, Dev* ref ) )
{
        Dev* obj = calloc ( 0, sizeof ( dev ) );
        
        obj -> devId = devId;
        snprintf ( obj -> desc, MAXDESC, "%s", 
}

#ifdef __cplusplus
}
#endif

#endif /* End dev_h */
