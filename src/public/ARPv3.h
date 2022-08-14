/*
 *
 * Header file to contain functions
 * and data structures for ARPv3
 *
 *
 * @QWERTYghri
 *
 */

#ifndef ARP_H
#define ARP_H

#include <stdint.h>
#include "./handler.h" /* Function decleration of instructions */      

typedef enum defList
{
        ISAMAX  = 34,
        MAXADDR = 0xffff
} defList;

/* CPU DATA SECTION */
typedef struct s_flg
{
        uint8_t OV : 1;
        uint8_t SK : 1;
        uint8_t CM : 1;
} s_flg;

typedef struct ARP
{
        int16_t         AC,
                        X,
                        PC;

        uint8_t         SR;
        uint8_t		MBR, CIR;

        /* Flag reg is set to struct three bits that represent the
           individual flags.
        */
        
        uint8_t		Bus[0xffff];
        
        s_flg flg;
} ARP;

/* Function definitions for system */
void reset      ( ARP* lnk );
void immFetch   ( ARP* lnk );
void dirFetch   ( ARP* lnk );
/* void clock      ( ARP* lnk ); */
/* void setBus ( ARP* lnk, Bus* cBusLk ); */

#endif /* end */
