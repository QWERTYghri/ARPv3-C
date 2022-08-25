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
#include "bus.h"

/* Const Defs */
#define ISAMAX	30
#define MAXADDR ( ( uint16_t ) 1024 * 64 )
#define NOPC	30


enum ADDRMODE {
        NOM	= 1, /* No Mode */
        IMM	= 2,
        DIR	= 3,
};

enum FLAGVAL {
        OV	= 4,
        SK	= 5,
        CM	= 6,
};

/* CPU DATA SECTION */

typedef struct ARP
{
        int16_t         AC,
                        X;
        
        uint16_t        PC;
        uint8_t         SR;
        
        uint16_t	MBR, CIR;
        Bus*		mBus;
        uint64_t	clkCnt;
        
        struct flg
	{
        	uint8_t OV : 1;
        	uint8_t SK : 1;
        	uint8_t CM : 1;
	} flg;
} ARP;

/* Data Stuff */
typedef void ( *p_Func ) ( ARP* );
typedef struct i_set
{
	p_Func inst;
	int32_t addrMd;
} i_set;

/* Function definitions for system */
void reset      ( ARP* lnk, uint16_t init );
void fReset	( ARP* lnk );
void immFetch   ( ARP* lnk );
void dirFetch   ( ARP* lnk );
void fDebug	( ARP* lnk, FILE* fp );
void clock	( ARP* lnk, uint16_t cyc );
void step	( ARP* lnk );
void writeInst	( ARP* lnk, uint16_t addr, uint16_t opCode, int16_t operand );
void writeData	( ARP* lnk, uint16_t addr, int16_t data );
void loadFile	( ARP* lnk, FILE* fp, uint16_t stAddr );
void setFlag	( ARP* lnk, int32_t flg, int32_t val );


#endif /* end */
