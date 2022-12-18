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
        char desc[MAXDESC];

        void ( *tick ) ( Bus* lnk, Dev* ref ); 
        uint16_t rng1, rng2; /* rng1 must be less than rng2 otherwise it'll fail */
} Dev;

/* Functions */
Dev* newDev ( uint16_t devId,
              char* desc,
              void ( *tick ) ( Arp* lnk, Dev* ref ),
              uint16_t rng1,
              uint16_t rng2 );

void delDev     ( Dev* lnk );
#endif /* End dev_h */
