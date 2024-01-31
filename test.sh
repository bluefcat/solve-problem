#!/bin/bash
target=$(find . -name $(printf "%s.c" $1))
printf "[%s is compiling now]\n" $target 

gcc $target -O2 -Wall -lm -static -std=gnu99 -o ./a.out

input_list=$(find . -name $(printf "%s_*.txt" $1))
idx=0
for input in $input_list
do
	printf "TESTCAST #%s\n>>>>>\n" $idx
	cat $input
	printf "<<<<<\n%s\n\n" $(./a.out < $input) 
	idx=$(($idx+1))
done


