/* 
 * arp.h
 *
 * Holds the interface for the cpu
 */

#ifndef ARP_H
#define ARP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Libc / POSIX */
#include <time.h>
#include <stdlib.h>

/* Local */
#include "./bus.h"
#include "./def.h"
#include "./dev.h"

typedef struct Arp {
        struct reg {
                int16_t R0, R1, R2, R3;
                uint16_t PC, SP, SBP, MBR;

                uint8_t flg;
        } reg;

        struct util {
                
        } util;
} Arp;

Arp*
newArp ( void )
{
        Arp* lnk = malloc ( sizeof ( Arp ) );

        lnk -> reg.R0 = 0;


#ifdef __cplusplus
}
#endif

#endif
