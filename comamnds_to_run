#!/bin/bash

bison -d -t snazzle.y

flex snazzle.l

g++ snazzle.tab.c lex.yy.c -lfl -o snazzle
