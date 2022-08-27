ARPv3
===================

About
-------------------

ARPv3 is a recreation of ARPv2 that I used for Roblox development in making a sort of PDP-8 "emulator".
It existed to have it's own architecture against the original PDP-8. This is a recreation of the project
in C in order to have some correlation to the PDP-8 without the restrictions in Luau.

This is a 16-bit cpu.

This will allow for the creation of peripherals that act on the CPU bus. The peripherals are built on a handler.h decleration with
functions working in threads to run the peripheral parallel to the cpu.

The peripheral can write to the bus and do other operations.

Peripherals can be made to preform other tasks such as using the values sent in the Bus to write to a file.


Architecture
-------------------

16-bit cpu

**Registers**
Registers are the same as the original

`Register's AC, X are 8 bits wide with 16 bit word versions`
`Stack register is 8 bits wide to keep a 255 wide stack space.`

* E/AC : Accumulator registers to interract with arithematic operations
* E/X  : Multi-purpose registers to store values to act with AC or use for incrementation
* SR : Stack register initializes to $000
* PC : 16 bits wide

* MBR : Memory buffer reg 16 bits for operand
* CIR : Instruction register 16 bits


**CPU Flags**
Flags have changes, OV/SK have been added

* OV : Overflow of any register.
* SK : Stack overflow flag
* CM : A register to match 6 branch instructions, the branches check the CM to check how the comparison worked.
* BM : Bit size mode, Switches between normal function handlers and addressing modes for 16 bit and 8 bit mode.

**Instructions**
There are a multitude of instructions that are also set for different addressing modes.

**Addressing modes**

Addressing modes fetch data depending on the instruction demand which is defined in a struct with function pointer to it.

* Immediate 8/16	: Fetch from register
* Direct    8/16	: Fetch/Store from an address
* Imp	    none	: No data is being fetched

There exists two modes for these two modes that dictate for the varying sizes of the stored word. There can be direct 16 bit address or 8 bit.
The 16 bit mode should fetch from the two cells containing the parts of the 16 bit value and then have it parse through the instructions.

Note the instructions are going to be abstracted from
Some instructions that write to memory may have to be duplicated
It's repetitive but I just want to specify

`%`: Means there's a 8/16 bit version of the instruction
`^`: 16 bit usage

The first instruction in a % instruction is the 8 bit verision the next is the 16 bit

**Register Load**
* 0	NOP	NON	No instruction
* 1/2	LDA	IMM%	Load 8/16 bit value into AC
* 3/4	LDA	DIR%	Load value in the addr specified by 8/16 bits to ac

* 5/6	STA	IMM%	Store 8/16 bit val to addr from AC
* 7/8	GTA	IMM%	Get 8/16 bit val from addr to AC

* 9/10	LDX	IMM%	Load 8/16 bit value into X
* 11/12	LDX	DIR%	Load 8/16 bit val from addr to X

* 13/14	STX	IMM%	Store 8/16 bit val to addr from X
* 15/16	GTX	IMM%	Get 8/16 bit val from addr to X

**Register Transfers**
* 17/18	TAX	NON%	Load AC to the X reg 8/16
* 19/20	TXA	NON%	Load X to the AC 8/16
* 21	TSX	NON	Load SR to X | Clears X in process
* 22	TXS	NON	Load X to SR | R side of 16 bit reg is removed.

**Stack Operations**
* 23/24	PHA	NON%	Push the 8/16 bit LVal in AC to the memory pointed by SR
* 25/26	POA	NON%	Pop the SR pointed 8/16 bit val to AC and decrement the SR

**Arithemetic Operations**
* 27/28	ADD	IMM%	Add AC with 8/16 bit mem operand
* 29/30	ADA	DIR%	Add AC with an 8/16 bit val from the addr

* 31/32	SUB	IMM	Sub AC with 8/16 bit mem operand
* 33/34	SBA	DIR	Sub AC with an 8/16 bit val from the addr

* 35	INX	NON	Increment the X register
* 36	DEX	NON	Decrement X register

* 37	ADX	NON	Add AC by X reg
* 38	SUX	NON	Sub AC by X reg

**Branching**
Use AC as the first comparison operand
`AC (OP) ImmVal`

Branch instructions are dependent on CMP
* 39	JE	IMM^	jmp if AC == Op
* 40	JNE	IMM^	jmp if AC != Op
* 41	JG	IMM^	jmp if AC > Op
* 42	JGE	IMM^	jmp if AC >= Op
* 43	JL	IMM^	jmp if AC < Op
* 44	JLE	IMM^	jmp if AC <= Op

* 45	JMP	IMM^	jmp to addr
* 46	CMC	NON	Clear CM flag

* 47	CMP	IMM%	Use to compare the AC to the operand, and set a val in CM that allows for a jmp

**Functions**
* 48	CALL	IMM^	Call to an addr, push PC and then jump to operand addr
* 49	RET	NON	Pop the stored PC to the PC and return to control flow




Design Stuff
============
I might intend to add Interrupts but welp

Most of the functions are state-based rather than returning a value that gets used to edit a set. They're typically accepting an ARP struct as an arg and then edits the state
of the struct.

Project Files
-------------------
* ARPv3.h: The main control for the emulator, containing the step function, clock set, and other crucial stuff.
* handler.h: A list of declerations to map out to functions that'll be used as instructions, the definitions are in ../public/handler.c
* utila.h: Header containing declerations of some useful functions, load file into a section of memory.
* bus.h: Definition to set up a bus section for an `ARP` to handle data to.
* perph.h: Handles for peripherals that are set up in threads to interact with a specified `ARP`'s bus data.
	
These have their functions defs and other stuff in src/private

Jump table is set to 0 - ISAMAX but takes from 1 - ISAMAX.


ARPv3.h
-----------------
**Functions**
* init:		Allocate space for ARP struct, call reset, then return pointer to
* reset:	Reset the argument ARP to default values and set PC.
* immFetch	Fetch a memory operand to mbr
* dirFetch	Fetch the value at an address to mbr
* fDebug	Output a debug string to a stream
* clock		Clock cycle execution
* step		Step one cycle.
* writeInst	Write into an address and opcode and operand
* writeData	Write data into an address 

Buses
------------
Bus.h is used to set a module to create buses. A `Bus` type is used to set up a address space for a Cpu.
In ARPv3.h, the setBus function is used to alter an argument `ARP` struct that contains a Bus type that the functions map out to.

A bus struct contains a set of pointers that can contain a sector of bytes that all max out to 0xFFFF bytes. It's set up to setMem to alloc the memory sectors in the Bus* map. The Read/Write is set to
allocate to those different sectors.




