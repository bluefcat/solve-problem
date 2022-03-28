#!/bin/bash

list=$(find . -name '*.c')

for var in $list 
do
	gcc $var -O2 -Wall -lm -static -std=gnu99
done

