CC      := gcc
CFLAGS  := -std=gnu99 -Wpedantic -Wall -Wextra -pipe


#optimizaation flags
OFLAGS  := -g -O0
#OFLAGS  := -0s


#DIRS
OUTDIR  := ./bin
PUBLIC  := ./src/public
PRIVATE := ./src/private

ARCHIVE := ar
ARFLG   := -rc
