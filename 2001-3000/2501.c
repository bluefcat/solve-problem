#include <stdio.h>

int cache[20001];
int cnt;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	int f = 1;
	while(f <= n){
		if(n % f == 0) cache[cnt++] = f;
		f ++;
	}

	printf("%d\n", cache[k-1]);

	return 0;
}
