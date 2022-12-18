/*
 * bus.h
 *
 * Header file for bus set
 */

#ifndef BUS_H
#define BUS_H

#include <stdint.h>

#include "./arp.h"
#include "./dev.h"

#define MAX_DEV ( 255 )

typedef struct {
        uint16_t addr;

        Dev devices[MAX_DEV];
} Bus;



#endif /* END */
