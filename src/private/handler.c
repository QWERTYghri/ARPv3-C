/*
 * Function definitions for ARPv3
 *
 * @QWERTYghri
 *
 */

#include "../public/handler.h"
#include "../public/ARPv3.h"

/* Redundancy is  pain */
/* The functions will be classed into a struct containing the fetch mode and cpu cycles */
/* Different functions are commented out because they'll be implemented using a function of same code but with different fetches */

/* Register instructions */
void LDA ( ARP* lnk ) { lnk -> AC =  lnk -> MBR; }
void STA ( ARP* lnk ) { lnk -> Bus[lnk -> MBR] = lnk -> AC; }

void LDX ( ARP* lnk ) { lnk -> X =  lnk -> MBR; }
void STX ( ARP* lnk ) { lnk -> Bus[lnk -> MBR] = lnk -> X; }

/* Register Transfer */
void TAX ( ARP* lnk ) { lnk -> X = lnk -> AC; }
void TXA ( ARP* lnk ) { lnk -> AC = lnk -> X; }

void TSX ( ARP* lnk ) { lnk -> X = lnk -> SR; }
void TXS ( ARP* lnk ) { lnk -> SR = lnk -> X; }

/* Stack operations */
void PHA ( ARP* lnk ) { lnk -> Bus[lnk -> SR] = lnk -> AC; lnk -> SR++; }
void POA ( ARP* lnk ) { lnk -> AC = lnk -> Bus[lnk -> SR]; SR--; }

void PSD ( ARP* lnk ) { lnk -> SR -= lnk -> AC; }
void PSA ( ARP* lnk ) { lnk -> SR -= lnk -> MBR; }
void PAD ( ARP* lnk ) { lnk -> SR += lnk -> AC; }
void PAA ( ARP* lnk ) { lnk -> SR += lnk -> MBR; }

/* Arithemetic */
void ADD ( ARP* lnk ) { lnk -> AC += lnk -> MBR; }
void SUB ( ARP* lnk ) { lnk -> AC -= lnk -> MBR; }
void INX ( ARP* lnk ) { lnk -> X++; }
void DEC ( ARP* lnk ) { lnk -> X--; }
void ADX ( ARP* lnk ) { lnk -> AC += lnk -> X; }
void SUX ( ARP* lnk ) { lnk -> AC -= lnk -> X; }

/* Comparison */
void CPX ( ARP* lnk ) { ( lnk -> X == lnk -> MBR ) ? lnk -> flg.CM = 1 : 0; }
void CPA ( ARP* lnk ) { ( lnk -> AC == lnk -> MBR ) ? lnk -> flg.CM = 1 : 0; }
void CLC ( ARP* lnk ) { lnk -> flg.CM = 0; }

/* Functions / Jumps */
void JMP ( ARP* lnk ) { lnk -> PC = lnk -> MBR; }
void JLC ( ARP* lnk ) { ( lnk -> flg.CM == 1 ) ? lnk -> PC = lnk -> MBR : 0; }
void JMS ( ARP* lnk )
{
	lnk -> Bus[lnk -> SR] = lnk -> PC;
	lnk -> SR++;
	lnk -> PC = lnk -> MBR;
}

void RET ( ARP* lnk )
{
	lnk -> SR--;
	lnk -> PC = lnk -> Bus[lnk -> SR];
}


