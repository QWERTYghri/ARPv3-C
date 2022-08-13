/*
 * Function definitions for ARPv3
 *
 * @QWERTYghri
 *
 */

#include <stdint.h>
#include "../public/ARPv3.h"
#include "../public/handler.h"

void reset ( ARP* lnk )
{
        lnk -> AC	= 0;
        lnk -> X 	= 0;
        lnk -> SR	= 0;

        lnk -> PC	= 0xff;
	lnk -> MBR	= 0;
	lnk -> CIR	= 0;
        lnk -> flg.OV	= 0;
        lnk -> flg.SK	= 0;
        lnk -> flg.CM	= 0;
       	
        /* Temp bus stuff */
        for ( int i = 0; i <= MAXADDR; i++ )
        	lnk -> Bus[i] = 0;
}

void immFetch ( ARP* lnk )
{
	/* wtf? cir = Bus[pc] */
	lnk -> CIR = lnk -> Bus[lnk -> PC];
	lnk -> PC++;
	
	/* welp mbr = Bus[pc] */
	lnk -> MBR = lnk -> Bus[lnk -> PC];
	lnk -> PC++;
}

void dirFetch ( ARP* lnk )
{
	/* Get opt cir = Bus[pc]*/
	lnk -> CIR = lnk -> Bus[lnk -> PC];
	lnk -> PC++;
	
	/* get value from operand and use it to address from Bus to store mbr
	 * MBR = bus[ bus[pc] ]
	 */
	lnk -> MBR = lnk -> Bus[ Bus[lnk -> PC] ];
	lnk -> PC++;
}
