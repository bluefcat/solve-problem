#include <stdio.h>
#include <assert.h>

int cache[201];

int get_parent(int x){
	if(x == cache[x]) return x;

	return cache[x] = get_parent(cache[x]);
}

void union_set(int x, int y){
	x = get_parent(x);
	y = get_parent(y);

	cache[x] = y;

	return;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	assert(0<= n && n <= 200);
	assert(0<= m && m <= 1000);

	for(int i = 1; i <= n; i ++) cache[i] = i;
	
	for(int src = 1; src <= n; src ++){
		for(int dest = 1; dest <= n; dest ++){
			int check = 1;
			scanf("%d", &check);
			if(check) union_set(src, dest);
		}
	}


	int tmp = 1, p = 0;
	scanf("%d", &tmp);
	p = get_parent(tmp);

	for(int i = 1; i < m; i ++){
		scanf("%d", &tmp);
		if( p != get_parent(tmp)){
			printf("NO\n");
			return 0;
		}
	}
		
	printf("YES\n");
	
	return 0;
}
