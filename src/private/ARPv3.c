/*
 * Function definitions for ARPv3
 */

#include <stdint.h>
#include <stdlib.h>
#include "../public/ARPv3.h"
#include "../public/handler.h"

/* Instruction init */

i_set iList[ISAMAX] =
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
		{ SUX, NOM },
		
		{ CPX, IMM },
		{ CPA, IMM },
		{ CPX, DIR }, /* CXA */
		{ CPA, DIR }, /* CAA */
		{ CLC, NOM },
		
		{ JMP, IMM },
		{ JLC, NOM },
		{ JMS, NOM },
		{ RET, NOM }
};

void reset ( ARP* lnk, uint16_t initPc )
{
        lnk -> AC	= 0;
        lnk -> X 	= 0;
        lnk -> SR	= 0;

        lnk -> PC	= initPc;
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
	fprintf ( fp, "CYC: %ld\n\tAC: %d\n\tX: %d\n\tSR: %d\n\tPC: $%d\n\tMBR: %d\n\t"
		      "CIR: %d\n\nFlags:\n\t\tOV: %d\n\t\tSK: %d\n\t\tCM: %d\n\n\n",
		      lnk -> clkCnt, lnk -> AC, lnk -> X, lnk -> SR, lnk -> PC, lnk -> MBR,
		      lnk -> CIR, lnk -> flg.OV, lnk -> flg.SK, lnk -> flg.CM );
}

/* Computation set */
void step ( ARP* lnk )
{
	insFetch ( lnk );
	int32_t jVar = ( lnk -> CIR == 0 ) ? 0 : ( lnk -> CIR-- );
	
	if ( iList[jVar].addrMd == IMM )
		immFetch ( lnk );
	else if ( iList[jVar].addrMd == DIR )
		dirFetch ( lnk );
	else if ( iList[jVar].addrMd == NOM )
		lnk -> PC++; /* do nothing */
	iList[jVar].inst ( lnk );
	
	lnk -> clkCnt++;
}

void writeMem ( ARP* lnk, uint16_t addr, uint16_t opCode, int16_t operand )
{
	lnk -> Bus[addr] = opCode;
	lnk -> Bus[addr + 1] = operand;
}
