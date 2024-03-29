# Compilation flags and other stuff
# QWERTY

#Compilation
CC		:= gcc
# Note, removed -std=gnu99 and -Wpedantic in order to use binary literals for now
CFLAGS 		:= -Wall -Wextra -pipe
CPPFLAGS	:= -D_POSIX_C_SOURCE=200809L

#Optimization
OFLAGS		:= -g -O0
#OFLAGS		:= -0s

#Installation
LNAME		:= libarp.so
LIB_PREFIX	:= /usr/local/lib
INCLUDE_PREFIX	:= /usr/local/include
HEADER_FOLDER	:= arp
