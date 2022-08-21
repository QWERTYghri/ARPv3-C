ARPv3
===================

About
-------------------

ARPv3 is a recreation of ARPv2 that I used for Roblox development in making a sort of PDP-8 "emulator".
It existed to have it's own architecture against the original PDP-8. This is a recreation of the project
in C in order to have some correlation to the PDP-8 without the restrictions in Luau.

This will allow for the creation of peripherals that act on the CPU bus. The peripherals are built on a handler.h decleration with
functions working in threads to run the peripheral parallel to the cpu.

The peripheral can write to the bus and do other operations.

Peripherals can be made to preform other tasks such as using the values sent in the Bus to write to a file.


Architecture
-------------------

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
* CM : Comparison Register Set when a comparison instruction sets it off, a branch clears it or a clc
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

**Register Loading**
* 01	LDA Imm	Load the accumulator with memory operand
* 02	STA Dir	Store accumulator value into the address memory operand
* 03	GTA Dir	Get the value from address and store in Accumulator
* 04	LDX Imm	Load the accumulator with memory operand
* 05	STX Dir	Store the value in X into memory address operand
* 06	GTX Dir	Get the value from address operand and store in X

**Register Transfer**
* 07	TAX	Load AC val to X reg
* 08	TXA	Load X val to AC reg
* 09	TSX	Load SR val to X
* 10	TXS	Load X to SR reg

**Stack Operations**
* 11	PHA	Push Accumulator into memory stack and increment SR
* 12	POA	Pop value in memory to accumulator and decrement SR

**Arithemetic Operations**
* 13	ADD Imm	Add AC with memory operand val
* 14	ADA Dir	Add AC val with val from memory address given by mem operand
* 15	SUB Imm	Sub AC val with memory operand val
* 16	SBA Dir	Sub AC val with value from memory address given by mem operand
* 17	INX	Increment X register
* 18	DEC	Decrement X register
* 19	ADX	Add AC register with X
* 20	SUX	Sub AC register with X

**Comparison**
* 21	CPX	Compare X reg val to memory operand
* 22	CPA	Compare AC reg val to memory operand
* 23	CXA	Compare X reg val to address operand val
* 24	CAA	Compare AC reg val to address operand val
* 25	CLC 	Clear CM val to 0

**Functions and jumps**
* 26	JMP	Jump to address val
* 27	JLC	Jump when CM flag is 1
* 28	JMS	Jump to address as subroutine / Store current PC val in stack and increment the SR
* 29	RET	Return from Subroutine val    / Store popped val into PC as the address to go back to
* 30	NOP	No operation / The CIR is put to NOP when a value isn't in the ISA range




Design Stuff
============
I might intend to add Interrupts but welp

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






