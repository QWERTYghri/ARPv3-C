/*
 * Function definitions for ARPv3
 */

#include "../public/handler.h"
#include "../public/ARPv3.h"
#include "../public/bus.h"


/* Redundancy is  pain */
/* The functions will be classed into a struct containing the fetch mode and cpu cycles */
/* Different functions are commented out because they'll be implemented using a function of same code but with different fetches */

/* Register instructions */
void LDA ( ARP* lnk ) { lnk -> AC =  lnk -> MBR; setFlag ( lnk, OV, lnk -> AC < 0 ); }
void STA ( ARP* lnk ) { Write ( lnk -> mBus, lnk -> MBR, lnk -> AC ); }

void LDX ( ARP* lnk ) { lnk -> X =  lnk -> MBR; }
void STX ( ARP* lnk ) { Write ( lnk -> mBus, lnk -> MBR, lnk -> X ); }

/* Register Transfer */
void TAX ( ARP* lnk ) { lnk -> X = lnk -> AC; }
void TXA ( ARP* lnk ) { lnk -> AC = lnk -> X; }

void TSX ( ARP* lnk ) { lnk -> X = lnk -> SR; }
void TXS ( ARP* lnk ) { lnk -> SR = lnk -> X; }

/* Stack operations */
void PHA ( ARP* lnk ) { Write ( lnk -> mBus, lnk -> SR, lnk -> AC ); lnk -> SR++; }
void POA ( ARP* lnk ) { lnk -> AC = Read ( lnk -> mBus, lnk -> SR ); lnk -> SR--; }

/* Arithemetic 
	Redundancy ew but I don't want to make a handler function just because of the flag changes
*/
void ADD ( ARP* lnk ) { lnk -> AC += lnk -> MBR; setFlag ( lnk, OV, lnk -> AC < 0 );}
void SUB ( ARP* lnk ) { lnk -> AC -= lnk -> MBR; setFlag ( lnk, OV, lnk -> AC < 0 ); }
void INX ( ARP* lnk ) { lnk -> X++; setFlag ( lnk, OV, lnk -> X < 0 ); }
void DEC ( ARP* lnk ) { lnk -> X--; setFlag ( lnk, OV, lnk -> X < 0 ); }
void ADX ( ARP* lnk ) { lnk -> AC += lnk -> X; setFlag ( lnk, OV, lnk -> X < 0 ); }
void SUX ( ARP* lnk ) { lnk -> AC -= lnk -> X; setFlag ( lnk, OV, lnk -> X < 0 ); }

/* Comparison */
void CPX ( ARP* lnk ) { ( lnk -> X == lnk -> MBR ) ? lnk -> flg.CM = 1 : 0; }
void CPA ( ARP* lnk ) { ( lnk -> AC == lnk -> MBR ) ? lnk -> flg.CM = 1 : 0; }
void CLC ( ARP* lnk ) { lnk -> flg.CM = 0; }

/* Functions / Jumps */
void JMP ( ARP* lnk ) { lnk -> PC = lnk -> MBR; }
void JLC ( ARP* lnk ) { ( lnk -> flg.CM == 1 ) ? lnk -> PC = lnk -> MBR : 0; }
void JMS ( ARP* lnk )
{
	Write ( lnk -> mBus, lnk -> SR, lnk -> PC );
	lnk -> SR++;
	lnk -> PC = lnk -> MBR;
}

void RET ( ARP* lnk )
{
	lnk -> SR--;
	lnk -> PC = Read ( lnk -> mBus, lnk -> SR );
}

