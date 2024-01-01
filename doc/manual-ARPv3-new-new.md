New ARP doc
===========

NOTE
-----------
Ok so this is some actual bullshit tbh.
I started this thing months ago and forgot about it then now I'm back here looking
at this shitty code that doesn't do what it's supposed to do.

I'm overhauling this entire fucking thing so I can actually use this for some stuff to mess with
or to have some idea to how making emulators work.

FDSFDSFJD:SLFJDS For fuck sake

About
------------
ARPv3 is a pseudo-emulator that's meant to be more idealistic and simpler than other architectures. I made this thing so I can kinda design my own
fake interface for "hardware" without any techincal jargon  while making it a bit more fun. It'll allow for the use of peripheral components on a
system bus.

It's a 16-bit cpu similiar to a PDP-11.

Architecture
------------

#### Info ####
* 16-bit Address Width / Memory is 1-byte per addr
* 16/8-bit Data Word
* mHz clock is not restricted however realism makes me want it to 3 mHz
* port mapped I/O, 255 ports which can send a `byte` or `short` from register R0 and receive to register R0
* Little Endian

#### Registers ####

NA := Not accessible

**General Purpose**
* R0 [16/8]
* R1 [16/8]
* R2 [16/8]
* R3 [16/8]

**Specificed**
* PC  [u16]          : Program counter, inst pointer to bus address
* SP  [u16]          : Stack pointer
* SBP [u16]          : Stack Base pointer for stack frames
* MBR [u16 NA]       : Data register for memory
* CIR [u8 NA]        : Instruction register
* FLG [u8]           : Flag register

Some Explanation
-------------------

**General Purpose Registers**

The GP registers can be operated have two different types of an instruction for one. There is the `short` instruction
and the `byte` instruction. The `byte` instruction only takes the least significant side of the register.

**Flag Register**

FLG [u8]

`[Z][N][V][ 3-bit sec ]`

* Z : Zero flag is a register is 0
* N : Negative flag is a register is negative
* V : Overflow flag if a register overflows

3 bit : 3 bit section for comparison
`!= : == : <= : < : > : >=`

**Memory layout**

The CPU has an addressable range of 16-bits ( 65,536 ). Each memory location can store a 8-bit word.
An instruction is fetched as an 16-bit value which contains data on stuff like address mode or the word type.
It then can fetch a `byte` or `short` as an operand.

#### Address Mode ####
Note that the `1_bw` specifies whether or not it takes a short or byte.

* Implied   : No fetching.
* Immediate : Get the operand value after the Opcode and store in MBR
* Direct    : Get a `short` to use as a pointer to a place in memory to fetch a a val and store in MBR.

* Register Imm  : Use the value in a register as operand
* Register dir  : Specified Register contains address of operand

#### Single Operand ####
Takes either short or byte value depending on `1_BW`. Uses the above addressing modes for getting the value

`[1_BW][3_AM][4_OPC]`

* `1_BW`: Specifies if the operand is taken as a `byte` or `word`
* `3_AM` : Specifies Addressing mode
* `4_OPC`: Specifes Operation

The address mode specifies how data is fetched, register mode uses the operand to
index a register 1 - 4 ( 0 - 3 ).

Instructions
------------

#### Misc ####


#### Register Moving ####


#### Stack Operations ####

#### Arithemetic Operations ####

#### Branching ####

#### Subroutines ####

#### Input Output ####

Devices
-------------------
Hardware devices can be emulated to be included into a bus. You define the hardware device
through the `dev.h` file which gives you the ability to define a `tick` function that
ticks based on the clock you set it. Use this to make like a screen or some shit.
