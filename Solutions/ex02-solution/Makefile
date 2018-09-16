.SILENT: test
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: leap suffix days test

test:
	./test.sh leap 4
	./test.sh suffix 16
	./test.sh days 19
