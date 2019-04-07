#!/bin/bash

as assembly_code.s -o assembly_code.o
ld assembly_code.o -o assembly_code
./assembly_code
echo $?
