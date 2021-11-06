#include <stdio.h>

int cache[1000001];

void swap(int* x, int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int get_parent(int x){
	if(cache[x] == x) return x;

	return cache[x] = get_parent(cache[x]);
}

void union_set(int x, int y){
	x = get_parent(x);
	y = get_parent(y);

	cache[x] = y;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	//init
	for(int i = 1; i <= n; i ++){
		cache[i] = i;
	}

	for(int i = 0; i < m; i ++){
		int oper, x, y;
		scanf("%d %d %d", &oper, &x, &y);

		if(oper == 0){
			union_set(x, y);
		}
		else{
			printf("%s\n", get_parent(x) == get_parent(y)? "YES": "NO");
		}

	}
	return 0;
}
