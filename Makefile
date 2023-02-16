GCC = gcc
TARGET = main

$(TARGET): main.o libfun.lib
	$(GCC) -static main.o -Llib -llibfun -o main.exe

main.o: main.c
	$(GCC) -c main.c -Ilib -o main.o

libfun.lib: fun.o
	ar rcs lib/libfun.lib lib/fun.o

fun.o: lib/fun.c
	$(GCC) -c lib/fun.c -o lib/fun.o