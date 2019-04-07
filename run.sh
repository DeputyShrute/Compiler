#!/bin/bash

as --32 --gstabs+ output.s -o output.o
ld -m elf_i386 output.o -o output
./output


