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

`Register's AC, X are 8 bits wide`
`Stack register is 8 bits wide to keep a 255 wide stack space.`

* AC : Accumulator registers to interract with arithematic operations
* X  : Multi-purpose registers to store values to act with AC or use for incrementation
* SR : Stack register initializes to $000
* PC : 16 bits wide

* MBR : Memory buffer reg 8 bits for operand
* CIR : Instruction register 8 bits


**CPU Flags**
Flags have changes, OV/SK have been added

* OV : Overflow of any register.
* SK : Stack overflow flag
* CM : Comparison Register Set when a comparison instruction sets it off, a branch clears it or a clc

**Instructions**
There are a multitude of instructions that are also set for different addressing modes.

**Addressing modes**

Addressing modes fetch data depending on the instruction demand which is defined in a struct with function pointer to it.

* Immediate	: Fetch from register
* Direct	: Fetch/Store from an address
* Imp		: No data is being fetched

There exists two modes for these two modes that dictate for the varying sizes of the stored word. There can be direct 16 bit address or 8 bit.
The 16 bit mode should fetch from the two cells containing the parts of the 16 bit value and then have it parse through the instructions.

**Register Loading**
* 0x01	LDA Imm	Load the accumulator with memory operand
* 0x02	STA Dir	Store accumulator value into the address memory operand
* 0x03	GTA Dir	Get the value from address and store in Accumulator
* 0x04	LDX Imm	Load the accumulator with memory operand
* 0x05	STX Dir	Store the value in X into memory address operand
* 0x06	GTX Dir	Get the value from address operand and store in X

**Register Transfer**
* 0x07	TAX	Load AC val to X reg
* 0x08	TXA	Load X val to AC reg
* 0x09	TSX	Load SR val to X
* 0x0A	TXS	Load X to SR reg

**Stack Operations**
* 0x0B	PHA	Push Accumulator into memory stack and increment SR
* 0x0C	POA	Pop value in memory to accumulator and decrement SR
* 0x0D	PSD 	Subtract the stack register by a value in AC register
* 0x0E	PSA Imm Subtract the stack register by the MBR
* 0x0F	PAD     Add the stack register by a value in AC register
* 0x10	PAA Imm	Add the stack register by the MBR

**Arithemetic Operations**
* 0x11	ADD Imm	Add AC with memory operand val
* 0x12	ADA Dir	Add AC val with val from memory address given by mem operand
* 0x13	SUB Imm	Sub AC val with memory operand val
* 0x14	SBA Dir	Sub AC val with value from memory address given by mem operand
* 0x15	INX	Increment X register
* 0x16	DEC	Decrement X register
* 0x17	ADX	Add AC register with X
* 0x18	SUX	Sub AC register with X

**Comparison**
* 0x19	CPX	Compare X reg val to memory operand
* 0x1A	CPA	Compare AC reg val to memory operand
* 0x1B	CXA	Compare X reg val to address operand val
* 0x1C	CAA	Compare AC reg val to address operand val
* 0x1D	CLC 	Clear CM val to 0

**Functions and jumps**
* 0x1E	JMP	Jump to address val
* 0x1F	JLC	Jump when CM flag is 1
* 0x20	JMS	Jump to address as subroutine / Store current PC val in stack and increment the SR
* 0x21	RET	Return from Subroutine val    / Store popped val into PC as the address to go back to




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

Buses
------------
Bus.h is used to set a module to create buses. A `Bus` type is used to set up a address space for a Cpu.
In ARPv3.h, the setBus function is used to alter an argument `ARP` struct that contains a Bus type that the functions map out to.






