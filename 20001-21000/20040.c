#include <stdio.h>

int cache[500001];

int get_parent(int x){
	if(cache[x] == x) return x;

	return cache[x] = get_parent(cache[x]);
}

int main(){
	int n, m, result = 0, flag = 0;
	
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i <= n; i ++) cache[i] = i;

	for(int i = 0; i < m; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		
		if(flag) continue;

		x = get_parent(x);
		y = get_parent(y);
		
		if(x < y) cache[y] = x;
		else if(x > y) cache[x] = y;
		else{
			result = i+1;
			flag = 1;
		}

	}

	printf("%d\n", result);

	return 0;
}
