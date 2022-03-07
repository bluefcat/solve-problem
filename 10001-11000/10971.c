#include <stdio.h>
#include <limits.h>

#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int n, w[11][11];
int visited[11];
int stack[11];
int cnt;
int result = INT_MAX;


void solve(int d){
	if(n == d){
		int sum = w[stack[cnt-1]][stack[0]];
		if(sum == 0) return;
		for(int i = 1; i < cnt; i ++) sum += w[stack[i-1]][stack[i]];

		result = MIN(result, sum);
		return;
	}

	for(int i = 0; i < n; i ++){
		if(visited[i]) continue;
		if(d > 0){
			if(w[stack[cnt-1]][i] == 0) continue;
		}

		visited[i] = 1;
		stack[cnt++] = i;

		solve(d+1);

		visited[i] = 0;
		cnt --;
	}
	return ;
}

int main(){
	scanf("%d", &n);

	for(int i = 0; i < n*n; i ++) scanf("%d", w[i/n] + (i%n));
	
	solve(0);

	printf("%d\n", result);

	return 0;
}
