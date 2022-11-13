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
##Registers

**General Purpose**
* R0
* R1
* R2
* R3

**Specificed**
* PC    : Program counter uint16, inst pointer to bus address
* SP    : Stack pointer

** ayo finish here **

The GP registers can be operated have two different types of an instruction for one. There is the `short` instruction
and the `byte` instruction. The `byte` instruction only takes the least significant side of the
