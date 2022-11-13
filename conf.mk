# Compilation flags and other stuff
# QWERTY

#Compilation
CC		?= gcc
CFLAGS 		:= -std=gnu99 -Wpedantic -Wall -Wextra -pipe
CPPFLAGS	:= -D_POSIX_C_SOURCE=200809L

#Optimization
OFLAGS		:= -g -O0
#OFLAGS		:= -0s
