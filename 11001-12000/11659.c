#include <stdio.h>

int cache[100001];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	scanf("%d", cache);
	for(int i = 1; i < n; i ++){
		scanf("%d", cache+i);
		cache[i] += cache[i-1];
	}
	
	while(m--){
		int a, b;
		scanf("%d %d", &a, &b);
		a-=2; 
		b--;
		
		printf("%d\n", a >= 0? cache[b]-cache[a]:cache[b]); 

	}
	
	return 0;
}
