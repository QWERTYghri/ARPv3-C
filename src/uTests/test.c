#include <stdio.h>
#include <stdlib.h>
#include "../public/ARPv3.h"

int main ( void )
{
        ARP* cpu = arpInit ( 255 );

        writeBInst ( cpu, 257, 1, 16 );
        
        while ( fgetc ( stdin )  )
        {
                step ( cpu );
                fDebug ( cpu, stdout );
        }

        arpDel ( cpu );

        return 0;
}

