#Makefile to compile objects to static library

include conf.mk

all: binDir lib mvAll

binDir:
	-mkdir $(OUTDIR)

lib: $(PUBLIC)/*.h $(PRIVATE)/*.c
	$(CC) $(CFLAGS) $(OFLAGS) -c $^
	$(ARCHIVE) $(ARFLG) $(SOUT) *.o

mvAll:
	-mv *.o *.a $(OUTDIR)

uTest: $(PUBLIC)/*.h ./src/uTests/*.c $(OUTDIR)/*.a
	$(CC) $(CFLAGS) $(OFLAGS) -o exec.out $^

clean:
	-rm -r *.o $(OUTDIR) *.a *.out

