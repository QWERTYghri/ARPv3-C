/*
 * Function definitions for ARPv3
 */

#include <stdint.h>
#include <stdlib.h>

#include "../public/ARPv3.h"
#include "../public/handler.h"
#include "../public/bus.h"


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
		{ RET, NOM },
		
		{ NOP, NOM }
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
       	
       	/* Make edit for setMem bus */
}

/* Free ARP struct */
void fReset ( ARP* lnk ) { free ( lnk ); };

/* Fetch instruction */
void insFetch ( ARP* lnk )
{
	uint16_t vCIR = Read ( lnk -> mBus, lnk -> PC );

	lnk -> CIR = ( vCIR > 0 && vCIR <= ISAMAX ) ? vCIR - 1 : NOPC;
	lnk -> PC++;
}


/* Addressing modes for operands */
void immFetch ( ARP* lnk )
{
	lnk -> MBR = Read ( lnk -> mBus, lnk -> PC );
	lnk -> PC++;
}

void dirFetch ( ARP* lnk )
{
	/* get value from operand and use it to address from Bus to store mbr MBR = bus[ bus[pc] ] */
	lnk -> MBR = Read ( lnk -> mBus, Read ( lnk -> mBus, lnk -> PC ) );
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

void clock ( ARP* lnk, uint16_t cyc )
{
	while ( cyc > 0 )
	{
		step ( lnk );
		cyc--; //temp
	}
}

/* Computation set some boiler plate here but welp*/
void step ( ARP* lnk )
{
	insFetch ( lnk );
	
	switch ( iList[lnk -> CIR].addrMd )
	{
		case NOM:
			lnk -> PC++;
			iList[lnk -> CIR].inst ( lnk );
			break;
		case IMM:
			immFetch ( lnk );
			iList[lnk -> CIR].inst ( lnk );
			break;
		case DIR:
			dirFetch ( lnk );
			iList[lnk -> CIR].inst ( lnk );
			break;
	}
}

void writeInst ( ARP* lnk, uint16_t addr, uint16_t opCode, int16_t operand )
{
	Write ( lnk -> mBus, addr, opCode );
	Write ( lnk -> mBus, addr, operand );
}

void writeData ( ARP* lnk, uint16_t addr, int16_t data ) { Write ( lnk -> mBus, addr, data ); }

void loadFile ( ARP* lnk, FILE* fp, uint16_t stAddr )
{
	int32_t bIn;
	
	while ( ( bIn = fgetc ( fp ) ) != EOF  )
	{
		Write ( lnk -> mBus, stAddr, bIn );
		stAddr++;
	}
}

void setFlag ( ARP* lnk, int32_t flg, int32_t val )
{
	switch ( flg )
	{
		case OV:
			lnk -> flg.OV = val;
			break;
		case SK:
			lnk -> flg.SK = val;
			break;
		case CM:
			lnk -> flg.CM = val;
			break;
	}
}
