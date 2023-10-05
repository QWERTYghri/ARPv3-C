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
enum addrMode {
	IMPLIED,
	IMMEDIATE,
	DIRECT,
	REGISTER_IMM,
	REGISTER_DIR
};

#endif /* END */
