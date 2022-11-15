#include <stdint.h>

Arp*
newArp ( uint16_t PC, )
{
        Arp* lnk = calloc ( 1, sizeof ( Arp ) ); /* Should init all to 0 */
        
        lnk -> PC = PC;
}
