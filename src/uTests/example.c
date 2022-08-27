#include "../public/ARPv3.h"

int main ( void )
{
	ARP* cpu = arpInit ( 0xff, 4, 255, 255, 255, 255 ); /* Malloc an ARP and set the PC to 0xff, And init 4 bus regions of 255 bytes, then return a pointer to the APR */
	writeInst ( cpu, 0xff, 0x01, 0x0f ); /* Write memory to the cpu ARP in mem $00ff with the opcode to load 15 to the AC register */
	
	step ( cpu ); /* run calculation in CPU arp */
	fDebug ( cpu, stdout ); /* Output a debug dump of cpu ARP to stdout */
	
	reset ( cpu ); /* reset values in cpu */
	
	arpDel ( cpu ); /* Remove cpu */
	
	return 0;
}
	