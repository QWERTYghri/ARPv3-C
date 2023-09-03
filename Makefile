# Makefile for ARP
#
# Compiles to shared library or static if specified
# Use install to install it to the usr lib path
#

include conf.mk

.PHONY: all extra install uninstall clean uTest
all: extra libarp.so main.out

extra:
	@echo -e "\033[32;1mARPv3-C\033[0m"
	@echo -e "\033[5;1mReady to launch missile\033[0m"
	@echo -e "\033[31;1mLAUNCHED!!!\033[0m"

libarp.so: ./src/public/*.h ./src/private/*.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OFLAGS) -fPIC -shared -lc -o $@ $^

main.out: ./src/uTest/*.c
	$(CC) $(CFLAGS) $(CCPFLAGS) $(OFLAGS) -o $@ $^

install:
	mkdir -p $(LIB_PREFIX) $(INCLUDE_PREFIX)/$(HEADER_FOLDER)
	
	cp -f *.so $(LIB_PREFIX)
	cp -f ./src/public/*.h $(INCLUDE_PREFIX)/$(HEADER_FOLDER)

uninstall:
	-rm -rf $(LIB_PREFIX)/libarp.so
	-rm -rf $(INCLUDE_PREFIX)/$(HEADER_FOLDER)
clean:
	-rm -f *.o *.out *.so
