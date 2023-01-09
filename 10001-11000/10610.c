#include <stdio.h>
#include <stdlib.h>

int compare(const void* x, const void* y){
	return *(char*)y - *(char*)x;
}

int main(){
	char x[100000] = { 0, };
	int length = 0;
	// sum is check 3
	// count is check 0's length
	int sum = 0, count = 0;

	scanf("%s", x);
	
	char * p = x;
	while(*p){
		length ++;
		sum += (*p) - '0';
		if(*p == '0') count ++;
		p ++;
	}
	
	if((sum % 3 != 0) || (count == 0)){
		printf("-1");
		return 0;
	}
	
	qsort(x, length, sizeof(char), compare);

	printf("%s\n", x);

	return 0;
}
