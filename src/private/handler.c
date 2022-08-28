/*
 * Function definitions for ARPv3
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
	lnk -> AC = lnk -> MBR;
}

void bSTA ( ARP* lnk ) { write ( lnk -> mBus, lnk -> MBR, ( lnk -> AC & 0xFF ) ); }
void wSTA ( ARP* lnk ) { writeWord ( lnk, lnk -> MBR, lnk -> AC ); }

/* X Reg equivalent */
void LDX ( ARP* lnk ) {
	lnk -> AC = lnk -> X;
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
void ADD ( ARP* lnk ) {
        lnk -> AC += lnk -> MBR;
}
