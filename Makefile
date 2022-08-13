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

all: dir lib

dir:
	mkdir $(OUTDIR)

lib: $(PUBLIC)/*.h $(PRIVATE)/*
	$(CC) $(CFLAGS) $(OFLAGS) -c $^
	mv $(OUTDIR)
	$(ARCHIVE) $(ARFLG) libarp.a $(OUTDIR)/*.o

uTest: $(PUBLIC)/*.h ./src/uTests/* $(OUTDIR)/*.o
	$(CC) $(CFLAGS) $(OFLAGS) $^

clean:
	rm -r *.o $(OUTDIR)

