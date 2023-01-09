#include <stdio.h>

#define AMAX 1000001
int cache[AMAX+1];

int count_zero(int p){
	int result = 0;
	do{
		if(p % 10 == 0) result ++;
		p /= 10;
	}while(p);
	return result;
}


int main(){
	cache[0] = 1;
	for(int i = 1; i < AMAX; i ++){
		int tmp = 0;

		cache[i] = count_zero(i) + cache[i-1];
	}

	int t;
	
	scanf("%d", &t);

	while(t--){
		int x, y;
		scanf("%d %d", &x, &y);

		printf("%d\n", cache[y] - cache[x] + count_zero(x));
	}

	return 0;
}
