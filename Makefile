#
#
# Shitty makefile
#
# Changes towards the compilation steps will be done later
# Set up the wildcards for unit test programs
#
# @QWERTYghri
#

include conf.mk

all: lib

lib: $(PUBLIC)/*.h $(PRIVATE)/*.c
	$(CC) $(CFLAGS) $(OFLAGS) -c $^
	mkdir $(OUTDIR) && mv *.o $(OUTDIR)
	$(ARCHIVE) $(ARFLG) $(SOUT) $(OUTDIR)/*.o

uTest: $(PUBLIC)/*.h ./src/uTests/* $(OUTDIR)/*.o
	$(CC) $(CFLAGS) $(OFLAGS) $^

clean:
	-rm -r *.o $(OUTDIR) *.a

