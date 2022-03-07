#include <stdio.h>

int cache[1001];

int main(){
	for(int i = 2; i < 1001; i ++) cache[i] = 1;

	int result = 0;
	int n, k;

	scanf("%d %d", &n, &k);

	for(int i = 2; i <= n; i ++){
		if(!cache[i]) continue;
		int cur = i, idx = 1;	

		int tmp = cur * idx;
		while(tmp <= n){
			if(cache[tmp] != 0) if((--k) == 0) result = tmp; 
			cache[tmp] = 0;
			tmp = cur * (++idx);
		}

	}

	printf("%d\n", result);

	return 0;
}
