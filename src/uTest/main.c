#include <stdio.h>

#include "../public/arp.h"

int main ( void )
{
	Bus* mem = newBus ( 0xFFFF );
	Arp* obj = newArp ( 16, mem );
	
	printf ( "%d\n", obj -> pc );
	obj -> memory -> memGroup[1] = 10;
	
	printf ( "%d\n", obj -> memory -> memGroup[1] );
	
	return 0;
}
