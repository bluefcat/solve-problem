#include <stdio.h>

int cache[100003];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", cache+i+1);
	
	int tmp = cache[1];
	for(int i = 2; i < n+1; i ++){
		cache[i] += tmp;
		tmp = cache[i];
	}

	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i ++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", cache[b] - cache[a-1]);
	}

	return 0;
}
