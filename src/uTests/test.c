#include <stdio.h>
#include <stdlib.h>
#include "../public/ARPv3.h"

int main ( void )
{
        FILE* set = fopen ( "out.log", "w+" );

        ARP* cpu = arpInit ( 255 );

        writeBInst ( cpu, 258, 1, 14 );
        writeWInst ( cpu, 301, 2, 1434 );

        while ( getchar () != 'Q' ) {
                step ( cpu );
                fDebug ( cpu, stdout );
        }

        fclose ( set );
        arpDel ( cpu );

        return 0;
}

