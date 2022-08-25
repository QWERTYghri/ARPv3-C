ARPv3
=============

About
-------------

This is a rendition of the ARPv2 "pseudo-emulator" to make a more realistic
processor. It exists as a header module to be included with a main program.

The manual for the ARP is updated and support for peripherals would be added

Header Interface
----------------
Interfacing with the data structures and instructions is done primarily through functions declared
in `ARPv3.h`. Most functions require the argument of an `ARP` struct to be used as to allow a sort of
object view for the CPU. And also to set up multiple different cores for some stuff.

Example Prog:
[Example.c](src/uTests/example.c)

Other
-------------
* Three addressing modes exist. Indirect/Direct/NoMode.
* The bus exists as a object defined in an `ARP` struct.
* Compilation outputs a static archive.


Compilation
-------------
Use Makefile to output binaries for it given the flags

To make edits to config in makefile use `Conf.mk`
Binaries are compiled into a `bin` directory

Compiled in C99 Standard `-std=gnu99`

Run `make` to output a `bin` directory which stores object files and a static archive file

```
clean: Remove ./bin and object files in proj directory.
uTest: Compile executables for unit tests
```
