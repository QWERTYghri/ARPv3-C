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
        lnk -> AC = 0;
        lnk -> X  = 0;
        lnk -> SR = 0;

        lnk -> PC = 0xff;

        lnk -> flg.OV = 0;
        lnk -> flg.OV = 0;
        lnk -> flg.OV = 0;
}

void fetch ( ARP* lnk )
{
        
