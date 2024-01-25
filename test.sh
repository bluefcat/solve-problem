#!/bin/bash
target=$(find . -name $(printf "%s.c" $1))
printf "[%s is compiling now]\n" $target 

gcc $target -O2 -Wall -lm -static -std=gnu99 -o ./a.out

input_list=$(find . -name $(printf "%s_*.txt" $1))

for input in $input_list
do
	echo $(./a.out < $input) 
done
echo ''

