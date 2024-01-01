#include <stdio.h>

#include "../public/arp.h"

int main ( void )
{
	Bus* mem = newBus ( 0xFFFF );
	Arp* obj = newArp ( 16, mem );
	
	obj -> memory -> memGroup[obj -> pc] = 0b00010001;
	step ( obj );
	
	return 0;
}
