/* 
 * arp.h
 *
 * Holds the interface for the cpu
 */

#ifndef ARP_H
#define ARP_H

#include <stdlib.h>
#include <time.h>

#include "./bus.h"
#include "./dev.h"

/* Defs */
#define MAXADDR ( ( unsigned ) 1024 * 64 )

/* Types */
typedef struct {
        /* Registers */
        int16_t R0, R1, R2, R3;
        uint16_t PC, SP, SBP, MBR;

        uint8_t CIR, FLG, MBA;

        Bus* mBus;
} Arp;

#ifdef __cplusplus
extern "C" {
#endif

/* **Functions** */

/* Note* if busArg is NULL, it'll use a 16-bit memory bus*/
Arp* newArp     ( uint16_t PC, Bus* busArg ); 
void delArp     ( Arp* lnk );


#ifdef __cplusplus
}
#endif

#endif /* END */
