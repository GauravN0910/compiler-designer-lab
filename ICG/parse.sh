#!/bin/bash


lex toylanglex.l

yacc -v -d toylangparser.y --warning=none
gcc y.tab.c -lm 


./a.out<input2.txt

