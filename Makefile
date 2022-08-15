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

all: binDir lib mvAll *.o *.a

binDir:
	-mkdir $(OUTDIR)

lib: $(PUBLIC)/*.h $(PRIVATE)/*.c
	$(CC) $(CFLAGS) $(OFLAGS) -c $^
	$(ARCHIVE) $(ARFLG) $(SOUT) *.o

mvAll:
	-mv *.o *.a $(OUTDIR)

uTest: $(PUBLIC)/*.h ./src/uTests/* $(OUTDIR)/*.o
	$(CC) $(CFLAGS) $(OFLAGS) $^

clean:
	-rm -r *.o $(OUTDIR) *.a

