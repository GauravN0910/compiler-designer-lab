#!/bin/bash


lex toylanglex.l

yacc -v -d toylangparser.y
gcc y.tab.c -lm


./a.out<input.txt

