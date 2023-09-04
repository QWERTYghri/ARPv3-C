#include <stdio.h>

#include "../public/arp.h"

int main ( void )
{
	Bus* mem = newBus ( 0xFFFF );
	Arp* obj = newArp ( 16, mem );
	
	obj -> memory -> memGroup[1] = 0b11111111;
	
	simulate ( obj, 2 );
	
	return 0;
}
