/*
 * Handler to store declerations of function instructions
 */

#ifndef HANDLER_H
#define HANDLER_H

#include "ARPv3.h"

/* Redundancy is  pain, I would rather rewrite everything than read my shitty code */


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

/* misc */
void NOP ( ARP* lnk );

/*
 * Register Instructions 
 */
void LDA ( ARP* lnk );

void bSTA ( ARP* lnk );
void wSTA ( ARP* lnk );

/* X equivalent */
void LDX ( ARP* lnk );

void bSTX ( ARP* lnk );
void wSTX ( ARP* lnk );

/* 
 *Register Transfers 
 */
void bTAX ( ARP* lnk );
void wTAX ( ARP* lnk );

void bTXA ( ARP* lnk );
void wTXA ( ARP* lnk );

void TSX ( ARP* lnk );
void TXS ( ARP* lnk );

/*
 * Stack Operations
 */
void bPHA ( ARP* lnk );
void wPHA ( ARP* lnk );

void bPOA ( ARP* lnk );
void wPOA ( ARP* lnk );


#endif /* HANDLER_H */
