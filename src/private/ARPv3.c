/*
 * Function definitions for ARPv3
 */

#include <stdint.h>
#include <stdlib.h>
#include "../public/ARPv3.h"
#include "../public/handler.h"

/* Instruction init */

iList =
	{
		{ LDA, IMM },
		{ STA, IMM },
		{ LDA, DIR }, /* GTA */	
		{ LDX, IMM },
		{ STX, IMM },
		{ LDX, DIR }, /* GTX */
		
		{ TAX, NOM },
		{ TXA, NOM },
		{ TSX, NOM },
		{ TXS, NOM },
		
		{ PHA, NOM },
		{ POA, NOM },
		{ PSD, NOM },
		{ PSA, IMM },
		{ PAD, NOM }, 
		{ PAA, IMM },
		
		{ ADD, IMM },
		{ ADD, DIR }, /* ADA */
		{ SUB, IMM },
		{ SUB, DIR }, /* SBA */
		{ INX, NOM },
		{ DEC, NOM },
		{ ADX, NOM },
		{ SUX, NOM }
		

ARP* initArp ( void )
{
	ARP* set = calloc ( 1, sizeof ( ARP ) );
	reset ( set );
	
	return set;
}

void reset ( ARP* lnk )
{
        lnk -> AC	= 0;
        lnk -> X 	= 0;
        lnk -> SR	= 0;

        lnk -> PC	= 0xff;
	lnk -> MBR	= 0;
	lnk -> CIR	= 0;
        lnk -> flg.OV	= 0;
        lnk -> flg.SK	= 0;
        lnk -> flg.CM	= 0;
       	lnk -> clkCnt	= 0;
       	
       	
        /* Temp bus stuff */
        for ( int32_t i = 0; i <= MAXADDR; i++ )
        	lnk -> Bus[i] = 0;
}

/* Fetch instruction */
void insFetch ( ARP* lnk )
{
	lnk -> CIR = lnk -> Bus[lnk -> PC];
	lnk -> PC++;
}


/* Addressing modes for operands */
void immFetch ( ARP* lnk )
{
	lnk -> MBR = lnk -> Bus[lnk -> PC];
	lnk -> PC++;
}

void dirFetch ( ARP* lnk )
{
	/* get value from operand and use it to address from Bus to store mbr MBR = bus[ bus[pc] ] */
	lnk -> MBR = lnk -> Bus[ lnk -> Bus[lnk -> PC] ];
	lnk -> PC++;
}

/* Pain */
void fDebug ( ARP* lnk, FILE* fp )
{
	fprintf ( fp, "CYC: %ld\n\tAC: %d\n\tX: %d\n\tSR: %d\n\tPC: $%x\n\tMBR: %d\n\t"
		      "CIR: %d\n\nFlags:\n\t\tOV: %d\n\t\tSK: %d\n\t\tCM: %d\n\n\n",
		      lnk -> clkCnt, lnk -> AC, lnk -> X, lnk -> SR, lnk -> PC, lnk -> MBR,
		      lnk -> CIR, lnk -> flg.OV, lnk -> flg.SK, lnk -> flg.CM );
}

/* Computation set */
void step ( ARP* lnk )
{
	insFetch ();
	if ( iList[lnk -> CIR].addrMd == IMM )
		immFetch ( lnk );
	else if ( iList[lnk -> CIR].addrMr == DIR
		dirFetch ( lnk );
	else if ( iList[lnk -> CIR].addrMr == NOM
		lnk -> PC++; /* do nothing */
	iList[lnk -> CIR].inst ();
}

void writeMem ( ARP* lnk, uint16_t addr, uint16_t opCode, int16_t operand )
{
	lnk -> Bus[addr] = opCode;
	lnk -> Bus[addr + 1] = operand;
}
