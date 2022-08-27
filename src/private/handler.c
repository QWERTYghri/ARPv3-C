/*
 * Function definitions for ARPv3
 */

#include "../public/ARPv3.h"
#include "../public/handler.h"

void NOP ( ARP* lnk ) { /* NOP is just here as a no instruction, also to satisfy the step */ }

/* Match to OP 1 - 4, change for addr modes*/
void LDA ( ARP* lnk ) {
	lnk -> AC = lnk -> MBR;
	lnk -> flg.OV = ( lnk -> AC < 0 ) ? 1 : 0;
}

void STA ( ARP* lnk ) {

}
