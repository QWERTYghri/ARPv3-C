#include <stdio.h>

#include "../public/arp.h"

int main ( void )
{
	Bus* mem = newBus ( 0xFFFF );
	Arp* obj = newArp ( 16, mem );
	
	obj -> memory -> memGroup[1] = 10;
	
	fetchData ( obj );
	
	return 0;
}
