#include <stdio.h>

int main(){
	int cache[1000001] = { 1, };
	for(int i = 2; i < 1000001; i ++) cache[i] = 1;

	int m, n;
	scanf("%d %d", &m, &n);

	
	int cur = 2;
	while(cur <= n){
		if(cache[cur] == 0) goto ADD;

		for(int i = cur+cur; i <= n; i += cur){
			cache[i] = 0;
		}
		
		ADD:
		cur ++;
	}
	
	for(int i = m; i <= n; i ++){
		if(cache[i]) printf("%d\n", i);
	}
	return 0;
}
