/*
 * Function definitions for ARPv3
 *
 * @QWERTYghri
 *
 */

#include <stdint.h>
#include "../public/ARPv3.h"

void reset ( ARP* lnk )
{
        lnk -> AC	= 0;
        lnk -> X 	= 0;
        lnk -> SR	= 0;

        lnk -> PC	= 0xff;
	lnk -> MBR	= 0;
	lnk -> CIR	= 0;
        lnk -> flg.OV	= 0;
        lnk -> flg.OV	= 0;
        lnk -> flg.OV	= 0;
        
        /* Temp bus stuff */
        
        for ( int i = 0; i <= MAXADDR; i++ )
        	lnk -> tempBus[i] = 0;
}

void immFetch   ( ARP* lnk )
{
	/* wtf? cir = tempBus[pc] */
	lnk -> CIR = lnk -> tempBus [lnk -> PC];
	lnk -> PC++;
	
	/* welp mbr = tempBus[pc] */
	lnk -> MBR = lnk -> tempBus [lnk -> PC];
	lnk -> PC++;
}

void dirFetch   ( ARP* lnk );
