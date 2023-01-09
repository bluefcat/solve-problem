#include <stdio.h>

int main(){
	const char* string = "SciComLove";
	const int length = 10;

	long long start;
	int idx, eidx;

	scanf("%lld", &start);

	idx = start % length;
	eidx = idx;
	
	do{
		printf("%c", string[idx]);
		idx = (idx + 1) % length;
	}while(idx != eidx);

	printf("\n");

	return 0;
}
