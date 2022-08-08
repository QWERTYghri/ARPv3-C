ARPv3
=============

About
-------------

This is a rendition of the ARPv2 "pseudo-emulator" to make a more realistic
processor. It exists as a header module to be included with a main program.

The manual for the ARP is updated and support for peripherals would be added

Compilation
-------------

Use Makefile to output binaries for it given the flags

To make edits to config in makefile use Conf.mk
Binaries are compiled into a bin directory

```
clean: Remove ./bin and object files in proj directory.
lib: Compile a static library of the module
uTest: Compile executables for unit tests
```
