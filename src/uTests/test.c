#include <stdio.h>
#include <stdlib.h>
#include "../public/ARPv3.h"
#include "../public/handler.h"

int main ( void )
{
	int32_t ch;

	ARP* cpu = calloc ( 1, sizeof ( ARP ) );
	reset ( cpu, 298 );
	
	FILE* fp = fopen ( "prog.bin", "r+" );
	
	loadFile ( cpu, fp, 300 );
	
	while ( ( ch = getc ( stdin ) ) != 'Q' )
	{
		fDebug ( cpu, stdout );
		step ( cpu );
	}
	return 0;
}

