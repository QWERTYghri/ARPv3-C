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

/* Functions */
Dev* newDev ( uint16_t devId,
              char* desc,
              void ( *tick ) ( Arp* lnk, Dev* ref ) );

void delDev ( Dev* lnk );

#endif /* End dev_h */
