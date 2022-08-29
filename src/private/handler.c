/*
 *  Function definitions for ARPv3
 */

#include "../public/ARPv3.h"
#include "../public/handler.h"

void NOP ( ARP* lnk ) { /* NOP is just here as a no instruction, also to satisfy the step */ }

/*
 * Register Loading
 */
/* GTX/GTA are used with the LDA func with DIR mode */


/* Match to OP 1 - 4, change for addr modes*/
void LDA ( ARP* lnk ) {
	lnk -> AC |= lnk -> MBR;
}

void bSTA ( ARP* lnk ) { write ( lnk -> mBus, lnk -> MBR, ( lnk -> AC & 0xFF ) ); }
void wSTA ( ARP* lnk ) { writeWord ( lnk, lnk -> MBR, lnk -> AC ); }

/* X Reg equivalent */
void LDX ( ARP* lnk ) {
	lnk -> AC |= lnk -> X;
}

void bSTX ( ARP* lnk ) { write ( lnk -> mBus, lnk -> MBR, ( lnk -> X & 0xFF ) ); }
void wSTX ( ARP* lnk ) { writeWord ( lnk, lnk -> MBR, lnk -> X ); }

/*
 * Register Transfers
 */
void bTAX ( ARP* lnk ) { lnk -> X = lnk -> AC & 0xFF; }
void wTAX ( ARP* lnk ) { lnk -> X = lnk -> AC; }

void bTXA ( ARP* lnk ) { lnk -> AC = lnk -> X & 0xFF; }
void wTXA ( ARP* lnk ) { lnk -> AC = lnk -> X; }

void TSX ( ARP* lnk ) { lnk -> X = lnk -> SR; }
void TXS ( ARP* lnk ) { lnk -> SR = ( lnk -> X & 0xFF ); }

/*
 * Stack Operations
 */
void bPHA ( ARP* lnk ) {
	write ( lnk -> mBus, lnk -> SR, lnk -> AC & 0xFF );
        lnk -> SR++;
} 

void wPHA ( ARP* lnk ) {
	writeWord ( lnk, lnk -> SR, lnk -> AC );
        lnk -> SR += 2;
}

void bPOA ( ARP* lnk ) {
	read ( lnk -> mBus, lnk -> SR );
        lnk -> SR--;
}

void wPOA ( ARP* lnk ) {
        lnk -> AC = readWord ( lnk, lnk -> SR );
        lnk -> SR++;
}

/*
 * Arithemetic
 */
void bADD ( ARP* lnk ) { lnk -> AC |= ( lnk -> AC & 0xFF ) + lnk -> MBR; }
void wADD ( ARP* lnk ) { lnk -> AC += lnk -> MBR; }

void bSUB ( ARP* lnk ) { lnk -> AC |= ( lnk -> AC & 0xFF ) + lnk -> MBR; }
void wSUB ( ARP* lnk ) { lnk -> AC += lnk -> MBR; }

void INX ( ARP* lnk ) { lnk -> X++; }
void DEX ( ARP* lnk ) { lnk -> X--; }

void bADX ( ARP* lnk ) { lnk -> AC = ( lnk -> AC & 0xFF ) + ( lnk -> X & 0xFF ); }
void wADX ( ARP* lnk ) { lnk -> AC += lnk -> X; }

void bSUX ( ARP* lnk ) { lnk -> AC = ( lnk -> AC & 0xFF ) + ( lnk -> AC & 0xFF ); }
void wSUX ( ARP* lnk ) { lnk -> AC -= lnk -> X; }

/*
 * Branching Instructions
 */

/* 
 * Wtf am I gonna do for this? It's gonna become boiler plate but I need
 * to get the comparison flag for this shit
 */
void bCMP ( ARP* lnk )
{
        if ( ( lnk -> AC & 0xFF ) == lnk -> MBR )
                lnk -> flg.OV = 1;
        else if 
