#Makefile to compile objects to static library

include conf.mk

all: binDir lib mvAll *.o *.a

binDir:
	-mkdir $(OUTDIR)

lib: $(PUBLIC)/*.h $(PRIVATE)/*.c
	$(CC) $(CFLAGS) $(OFLAGS) -c $^
	$(ARCHIVE) $(ARFLG) $(SOUT) *.o

mvAll:
	-mv *.o $(OUTDIR)

uTest: $(PUBLIC)/*.h ./src/uTests/* $(OUTDIR)/*.o
	$(CC) $(CFLAGS) $(OFLAGS) $^

clean:
	-rm -r *.o $(OUTDIR) *.a

