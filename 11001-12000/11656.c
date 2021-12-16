#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SMAX 1001

int compare(const void* x, const void* y){
	return strcmp((char*)x, (char *)y);
}

int main(){
	char string[SMAX] = { 0, };
	char dict[SMAX][SMAX] = { 0, };
	int size = 0;
	
	scanf("%s", string);

	char* p = string;

	while(*p){
		strcpy(dict[size++], p);
		p ++;
	}

	qsort(dict, size, sizeof(char)*SMAX, compare);

	for(int i = 0; i < size; i ++){
		printf("%s\n", dict[i]);
	}

	return 0;
}

