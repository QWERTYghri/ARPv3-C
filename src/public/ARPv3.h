/*
 *
 * Header file to contain functions
 * and data structures for ARPv3
 *
 */

#ifndef ARP_H
#define ARP_H

#include <stdint.h>   
#include <stdio.h>

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
                        X;
        
        uint16_t        PC;
        uint8_t         SR;
        
        uint16_t	MBR, CIR;
        int8_t		Bus[0xffff];
        uint64_t	clkCnt;
        
        s_flg flg;
} ARP;

/* Data Stuff */
typedef enum defList
{
        ISAMAX  = 34,
        MAXADDR = 0xffff,
        NOM	= 0, /* No Mode */
        IMM	= 1,
        DIR	= 2
} defList;

typedef void ( *pFunc ) ( ARP* );
typedef struct i_set
{
	pFunc inst;
	int32_t addrMd;
} i_set;

/* Function definitions for system */
void reset      ( ARP* lnk, uint16_t init );
void immFetch   ( ARP* lnk );
void dirFetch   ( ARP* lnk );
void fDebug	( ARP* lnk, FILE* fp );
void clock	( ARP* lnk, uint16_t cyc );
void step	( ARP* lnk );
void writeInst	( ARP* lnk, uint16_t addr, uint16_t opCode, int16_t operand );
void writeData	( ARP* lnk, uint16_t addr, int16_t data );
void loadFile	( ARP* lnk, FILE* fp, uint16_t stAddr );


#endif /* end */
