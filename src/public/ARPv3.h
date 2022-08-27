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
#define ISAMAX	49
#define MAXADDR ( ( uint16_t ) 1024 * 64 )
#define NOPC	0


enum ADDRMODE {
        NON	= 1, /* No Mode */
        B_IMM	= 2,
        B_DIR	= 3,
        W_IMM	= 4,
        W_DIR	= 5
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
        
        uint16_t	MBR;
        uint8_t		CIR;
        
        Bus*		mBus;
        uint64_t	clkCnt;
        
        struct flg
	{
        	uint8_t OV : 1;
        	uint8_t SK : 1;
        	uint8_t CM : 3; /* 0 - 7 */
	} flg;
} ARP;

/* Data Stuff */
typedef void ( *p_Func ) ( ARP* );
typedef struct i_set
{
	p_Func inst;
	int32_t addrMd;
} i_set;

/* 
 * Function definitions for interacing with ARP 
 */
 
/* Initialization functions */
void	reset		( ARP* lnk, uint16_t initPc );
void	arpInit		( uint16_t initPc, uint16_t secBus, ... );
void	arpDel		( ARP* lnk );

/* Fetch modes NOM not included and just done in step ()*/
void	insFetch	( ARP* lnk );

void	immBFetch	( ARP* lnk );
void	dirBFetch	( ARP* lnk );

void	immWFetch	( ARP* lnk );
void	dirWFetch	( ARP* lnk );

/* Computation functions */
void	fDebug		( ARP* lnk, FILE* fp );
void	clock		( ARP* lnk, uint16_t cyc );
void	step		( ARP* lnk );

/* Write data to bus instructions should be 8 bits wide*/
void	writeBInst	( ARP* lnk, uint16_t addr, uint16_t opCode, int16_t operand );
void	writeWInst	( ARP* lnk, uint16_t addr, uint16_t opCode, int16_t operand );

/* 16 bit mem assignment */
void	writeWord	( ARP* lnk, uint16_t addr, uint16_t data );
int16_t	readWord	( ARP* lnk, uint16_t addr );
/* 8 bit mem assignment is handled by bus.h write and read*/

void	loadFile	( ARP* lnk, FILE* fp, uint16_t stAddr );

/* Misc */

#endif /* end */
