#!/bin/bash

bison -d -t 2basic.y

flex 2basic.l

g++ 2basic.tab.c lex.yy.c -lfl -o 2basic

./2basic

as --32 --gstabs+ output.s -o output.o

ld -m elf_i386 output.o -o output

./output

