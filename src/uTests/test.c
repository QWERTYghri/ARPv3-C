#include <stdio.h>
#include <stdlib.h>
#include "../public/ARPv3.h"

int main ( void )
{
	ARP* cpu = arpInit ( 254 );

        for ( int i = 255; i <= 260; i++ )
                writeBInst ( cpu, i, i - 255, i - 43 );
        
        while ( getc ( stdin ) != 'Q' ) {
                step ( cpu );
                fDebug ( cpu, stdout );
        }

        arpDel ( cpu );

        return 0;
}

