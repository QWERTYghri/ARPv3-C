/*
 * Definitions file
 *
 * Holds macro definitions or constants
 */


#ifndef DEFINE_H
#define DEFINE_h

typedef int _;

/* General Definitions */
#define MAXADDR		( ( uint64_t ) 0xFFFF )
#define MAXPORT		( ( uint8_t ) 0xFF )

/* Address modes */
#define IMPLIED		( ( uint8_t ) 0 )
#define IMMEDIATE	( ( uint8_t ) 1 )
#define DIRECT		( ( uint8_t ) 2 )

#define REGISTER_IMM	( ( uint8_t ) 3 )
#define REGISTER_DIR	( ( uint8_t ) 4 )

#endif /* END */
