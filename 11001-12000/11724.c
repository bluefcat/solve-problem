#include <stdio.h>

int cache[1001];

int get_parent(int x){
	if(x == cache[x]) return x;
	return cache[x] = get_parent(cache[x]);
}

void union_set(int x, int y){
	x = get_parent(x);
	y = get_parent(y);

	if(x < y) cache[y] = x;
	else cache[x] = y;
}


int main(){
	int n, m, result = 0;
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i <= n; i ++) cache[i] = i;

	for(int i = 0; i < m; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		union_set(x, y);
	}

	for(int i = 1; i <= n; i ++){
		if(cache[i] == i) result ++;
	}

	printf("%d\n", result);

	return 0;
}
