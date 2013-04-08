# Makefile for this machine project
#
# To build, just use
#
# 		make
#
# To clean up the working directory, use
#
# 		make clean

CC=gcc
SOURCES=array-sort.c
EXECUTABLE=array-sorting
CFLAGS=-Wall -Wextra -Werror

# Setting up cleaning for either Linux or Windows
ifdef SystemRoot
	RM = del /Q
	FixPath = $(subst /,\,$1)
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
		FixPath = $1
	endif
endif

all:
	$(CC) $(SOURCES) -o $(EXECUTABLE) $(CFLAGS)
debug:
	$(CC) $(SOURCES) -o $(EXECUTABLE) $(CFLAGS) -g
clean:
	$(RM) $(call FixPath, *.o ./array-sorting*)
