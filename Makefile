# Makefile for ARP
#
# Compiles to shared library or static if specified
# Use install to install it to the usr lib path
#

include conf.mk

all: extra libarp.so install

extra:
	@echo -e "\033[32;1mARPv3-C\033[0m"
	@echo -e "\033[5;1mReady to launch missile\033[0m"
	@sleep 2
	@echo -e "\033[31;1mLAUNCHED!!!\033[0m"



libarp.so: ./src/public/*.h ./src/private/*.c
	$(CC) $(CFLAGS) $(OFLAGS) -fPIC -shared -lc -o $@ $^

install:
	
uninstall:

clean:

.PHONY: all extra install uninstall clean uTest
