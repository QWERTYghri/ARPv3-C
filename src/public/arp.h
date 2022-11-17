/* 
 * arp.h
 *
 * Holds the interface for the cpu
 */

#ifndef ARP_H
#define ARP_H



/* Libc / POSIX */
#include <time.h>
#include <stdlib.h>

/* Local */
#include "./bus.h"
#include "./util.h"
#include "./dev.h"

typedef struct Arp {
        /* Registers */
        int16_t R0, R1, R2, R3;
        uint16_t PC, SP, SBP, MBR;

        uint8_t flg;
        
        Bus* mBus;
} Arp;


#ifdef __cplusplus
extern "C" {
#endif

/* Functions */
Arp*
newArp ( uint16_t PC,  );

#ifdef __cplusplus
}
#endif

#endif /* END */
