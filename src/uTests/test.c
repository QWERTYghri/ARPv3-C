#include <stdio.h>
#include <stdlib.h>
#include "../public/ARPv3.h"

int main ( void )
{
	ARP* cpu = arpInit ( 255 );

        writeBInst ( cpu, 256, 1, 30 );
        step ( cpu );
        
        fDebug ( cpu, stdout );

        arpDel ( cpu );

        return 0;
}

