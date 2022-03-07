#include <stdio.h>

#define ABS(X) (((X) > 0)? (X): -(X))
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int result;
int n;
int cache[9];
int visited[9];

void solve(int d, int c, int tmp){
	if(d == n){
		result = MAX(result, tmp);
		return;
	}

	for(int i = 0; i < n; i ++){
		if(visited[i]) continue;
		visited[i] = 1;
		
		solve(d+1, i, tmp + ABS(cache[c] - cache[i]));
		visited[i] = 0;
	}

	return;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++) scanf("%d", cache+i);

	for(int i = 0; i < n; i ++){
		visited[i] = 1;
		solve(1, i, 0);
		visited[i] = 0;
	}
	
	printf("%d\n", result);
	return 0;
}
