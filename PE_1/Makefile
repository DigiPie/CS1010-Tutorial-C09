.SILENT: samplerun
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=/home/course/cs1010/include
CFLAGS=-g -Wall -Wextra -Wpedantic -I$(INCLUDEDIR) -L$(LIBDIR)
LIBDIR=/home/course/cs1010/lib

all: vote newton goldbach digits square samplerun

samplerun:
	./test.sh vote 2
	./test.sh newton 3
	./test.sh goldbach 3
	./test.sh digits 3
	./test.sh square 8

# vim:noexpandtab
