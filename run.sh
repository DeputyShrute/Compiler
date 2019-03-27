#!/bin/bash

as output.s -o output.o
ld output.o -o output
./output
echo $?
