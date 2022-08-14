/*
 * Handler to store declerations of function instructions
 *
 *
 * @QWERTYghri
 *
 */

#ifndef HANDLER_H
#define HANDLER_H

#include "ARPv3.h"

/* Redundancy is  pain */


/* Note that some instructions are missing because they're similiar to an immediate
 * addressing but just take direct addressing
 *
 * GTA
 * GTX
 * ADA
 * SBA
 * CXA
 * CAA
 */

/* Register instructions */
void LDA ( ARP* lnk );
void STA ( ARP* lnk );

void LDX ( ARP* lnk );
void STX ( ARP* lnk );

/* Register Transfer */
void TAX ( ARP* lnk );
void TXA ( ARP* lnk );

void TSX ( ARP* lnk );
void TXS ( ARP* lnk );

/* Stack operations */
void PHA ( ARP* lnk );
void POA ( ARP* lnk );

void PSD ( ARP* lnk );
void PSA ( ARP* lnk );
void PAD ( ARP* lnk );
void PAA ( ARP* lnk );

/* Arithemetic */
void ADD ( ARP* lnk );
void SUB ( ARP* lnk );
void INX ( ARP* lnk );
void DEC ( ARP* lnk );
void ADX ( ARP* lnk );
void SUX ( ARP* lnk );

/* Comparison */
void CPX ( ARP* lnk );
void CPA ( ARP* lnk );
void CLC ( ARP* lnk );

/* Functions / Jumps */
void JMP ( ARP* lnk );
void JLC ( ARP* lnk );
void JMS ( ARP* lnk );
void RET ( ARP* lnk );

#endif /* HANDLER_H */
