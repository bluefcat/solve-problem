#include <stdio.h>
#include <stdlib.h>

int n, m;
int cache[9];
int visited[9];

int stack[9];
int cnt;

int compare(const void* x, const void* y){
	return *(int*)x - *(int*)y;
}

void solve(int d){
	if(d == m){
		for(int i = 0; i < cnt; i ++) printf("%d ", stack[i]);
		printf("\n");
		return;
	}

	for(int i = 0; i < n; i ++){
		if(visited[i]) continue;

		visited[i] = 1;
		stack[cnt++] = cache[i];

		solve(d+1);
		
		visited[i] = 0;
		cnt --;
	}
	return;
}


int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++) scanf("%d", cache + i);

	qsort(cache, n, sizeof(int), compare);

	solve(0);
	
	return 0;
}
