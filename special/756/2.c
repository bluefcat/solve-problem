#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int cache[100001];
int mem[200002];


int main(){
	int k, n;
	scanf("%d %d", &k, &n);

	for(int i = 0; i < k; i ++){
		scanf("%d", cache + i);
		mem[i] = cache[i];
		if(i > 0) mem[i] += mem[i-1];
	}

	for(int i = k; i < (k << 1); i ++){
		mem[i] = cache[i-k];
		mem[i] += mem[i-1];
	}

	int result = 0;
	
	for(int i = n-1; i < (k << 1); i ++){
		int tmp = mem[i];
		if(i != n-1) tmp -= mem[i-n];
		result = MAX(result, tmp);
	}

	
	printf("%d\n", result);

	return 0;
}
