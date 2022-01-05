#include <stdio.h>

#define IS_ALPHA(X) ('A' <= (X) && (X) <= 'Z')

char cache[33];

unsigned int mpow(int x, int e){
	if(e == 0) return 1;
	if(e == 1) return x;

	if(e & 1) return x * mpow(x, e-1);

	unsigned int half = mpow(x, e >> 1);
	return half * half;
}

int main(){
	int b, result = 0;
	scanf("%s %d", cache, &b);
	
	int length = 0;
	char* p = cache;
	
	while(*(p++)){
		length ++;
	}

	for(int i = length-1; i >= 0; i --){
		int tmp = cache[i];
		
		if(IS_ALPHA(tmp)){
			tmp -= 'A';
			tmp += 10;
		}
		else{
			tmp -= '0';
		}

		result += tmp * mpow(b, (length-1)-i);
	}


	printf("%d\n", result);
	
	return 0;
}
