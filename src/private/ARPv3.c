/*
 * Function definitions for ARPv3
 */

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "../public/ARPv3.h"
#include "../public/bus.h"
#include "../public/handler.h"

/* Instruction init */
i_set iList[ISAMAX] =
	{
                /* AC Reg */
                { NOP, NON },

                { LDA, B_IMM },
                { LDA, W_IMM },

                { bSTA, NON },
                { wSTA, NON },

                { LDA, B_DIR }, /* GTA */
                { LDA, B_IMM },

                /* X Reg */
                { LDX, B_IMM },
                { LDX, W_IMM },

                { bSTX, NON },
                { wSTX, NON },

                { LDX, B_DIR }, /* GTX */
                { LDX, W_DIR },

                /* Reg Transfer */
                { bTAX, NON },
                { wTAX, NON },
                
                { bTXA, NON },
                { wTXA, NON },
                
                { TSX, NON },
                { TXS, NON },

                /* Stack Operations */
                { bPHA, B_IMM },
                { wPHA, W_IMM },

                { bPOA, NON },
                { wPOA, NON },

                /* Arithemetic */
                { bADD, B_IMM },
                { wADD, W_IMM },

                { bADD, B_DIR }, /* ada */
                { wADD, W_DIR },

                { bSUB, B_IMM },
                { wSUB, W_IMM },

                { bSUB, B_DIR }, /* sba */
                { wSUB, W_DIR },

                { INX, NON },
                { DEX, NON },

                { bADX, NON },
                { wADX, NON },

                { bSUX, NON },
                { wSUX, NON },

                /* Branching */
                { JE, W_IMM },
                { JNE, W_IMM },
                { JG, W_IMM },
                { JGE, W_IMM },
                { JL, W_IMM },
                { JLE, W_IMM },

                { JMP, W_IMM },
                { CMC, NON },

                { bCMP, B_IMM },
                { wCMP, W_IMM },

                { CALL, W_IMM },
                { RET, NON }
        };
 
/*----------------------------------------------------------------------*/

void reset ( ARP* lnk, uint16_t initPc )
{
	memset ( lnk, 0, sizeof ( ARP ) );
       	lnk -> PC = initPc;
}

void arpInit ( uint16_t initPc, uint16_t secBus, ... )
{
	ARP* lnk = calloc ( 1, sizeof ( ARP ) );
	reset ( lnk, initPc );
}

/* Free ARP struct */
void arpDel ( ARP* lnk ) {
	free ( lnk );
}

/*----------------------------------------------------------------------*/

/* Fetch instruction */
void insFetch ( ARP* lnk )
{
	uint16_t vCIR = read ( lnk -> mBus, lnk -> PC );

	lnk -> CIR = ( vCIR > 0 && vCIR <= ISAMAX ) ? vCIR - 1 : NOPC;
	lnk -> PC++;
}


/* Addressing modes for operands */
void immBFetch ( ARP* lnk ) {
	lnk -> MBR = read ( lnk -> mBus, lnk -> PC );
	lnk -> PC++;
}

/* Get 8 bit val at specified 16 bit addr */
void dirBFetch ( ARP* lnk ) {
	lnk -> MBR = read ( lnk -> mBus, readWord ( lnk, lnk -> PC ) );
	lnk -> PC += 2;
}

void immWFetch   ( ARP* lnk ) {
	
	lnk -> MBR = readWord ( lnk, lnk -> PC );
	lnk -> PC += 2;
}

void dirWFetch   ( ARP* lnk ) {
	lnk -> MBR = readWord ( lnk, readWord ( lnk, lnk -> PC ) );
	lnk -> PC += 2;
}

/*----------------------------------------------------------------------*/

/* Pain */
void fDebug ( ARP* lnk, FILE* fp )
{
	fprintf ( fp, "CYC: %ld\n\tAC: %d\n\tX: %d\n\tSR: %d\n\tPC: $%d\n\tMBR: %d\n\t"
		      "CIR: %d\n\nFlags:\n\t\tNV: %d\n\t\tOV: %d\n\n\t\tCF: %d\n\t\tCM: %d\n\n\n",
		      lnk -> clkCnt, lnk -> AC, lnk -> X, lnk -> SR, lnk -> PC, lnk -> MBR,
		      lnk -> CIR, lnk -> flg.NV, lnk -> flg.OV, lnk -> flg.CF, lnk -> flg.CM );
}

int simulate ( ARP* lnk, uint64_t hz )
{
        
}
/* Computation set some boiler plate here but welp*/
void step ( ARP* lnk )
{
	insFetch ( lnk );
	
	switch ( iList[lnk -> CIR].addrMd )
	{
		case NON:
			lnk -> PC++;
			iList[lnk -> CIR].inst ( lnk );
			break;
		case B_IMM:
			immBFetch ( lnk );
			iList[lnk -> CIR].inst ( lnk );
			break;
		case W_IMM:
			immWFetch ( lnk );
			iList[lnk -> CIR].inst ( lnk );
			break;
		case B_DIR:
			dirBFetch ( lnk );
			iList[lnk -> CIR].inst ( lnk );
			break;
		case W_DIR:
			dirWFetch ( lnk );
			iList[lnk -> CIR].inst ( lnk );
			break;
	}
}

/*----------------------------------------------------------------------*/

void writeBInst ( ARP* lnk, uint16_t addr, uint16_t opCode, int16_t operand )
{
	write ( lnk -> mBus, addr, opCode );
	write ( lnk -> mBus, addr++, operand );
}

void writeWInst ( ARP* lnk, uint16_t addr, uint16_t opCode, int16_t operand )
{
	write ( lnk -> mBus, addr, opCode );
	writeWord ( lnk, addr++, operand );
}

void writeWord	( ARP* lnk, uint16_t addr, uint16_t data )
{
	write ( lnk -> mBus, addr, ( data & 0xFF ) );
	write ( lnk -> mBus, addr++, ( data >> 8 ) );
}

int16_t	readWord ( ARP* lnk, uint16_t addr ) {
	return read ( lnk -> mBus, addr ) | ( read ( lnk -> mBus, addr + 1 ) << 8 );
}

void loadFile ( ARP* lnk, FILE* fp, uint16_t stAddr )
{
	int32_t bIn;
	
	while ( ( bIn = fgetc ( fp ) ) != EOF  )
	{
		write ( lnk -> mBus, stAddr, bIn );
		stAddr++;
	}
}

/*----------------------------------------------------------------------*/
