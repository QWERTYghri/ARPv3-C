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
* Memory banking to 255
* mHz clock is not restricted however realism makes me want it to 3 mHz
* Memory-mapped I/O cuz based

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
* MBA [u8]           : Memory banking info. Value specifies a memory bank from the Bus.
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

#### Addressing Modes ####
* Implied
* Immediate
* Direct
* Register
* Register Indirect

#### Instruction Layout ####

##### Inst Normal #####
`[1][--5--][-3-][offset]`

Instructions
------------

#### Misc ####
`NOP  : 0|00000 : NAN := `

#### Register Moving ####
`MOV  : 0|00001 : imm:dir:16:reg
`MOVB : 1|00001 : imm:dir:8:reg

#### Stack Pushing ####
`PSH  : 0|00010 : imm:dir:16:reg`
`PSHB : 1|00010 : imm:dir:8:reg`

`POP  : 0|00011 : imm:dir:16:reg`
`POPB : 1|00011 : imm:dir:8:reg`

#### Operators ####
`ADD  : 0|00100 : reg:`
`ADDB : 1|00100 : reg`

`SUB  : 0|00101 : reg`
`SUBB : 1|00101 : reg`

`INC  : 0|00110 : dir:reg`
`DEC  : 0|00111 : dir:reg`


Devices
-------------------
Hardware devices can be emulated to be included into a bus. You define the hardware device
through the `dev.h` file which gives you the ability to define a `tick` function that
ticks based on the clock you set it. Use this to make like a screen or some shit.
