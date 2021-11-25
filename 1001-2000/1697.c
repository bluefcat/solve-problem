#include <stdio.h>
#define MIN(X, Y) (((X) > (Y))? (Y): (X))
#define ABS(X) (((X) > 0)? (X): -(X))

int visited[100001];
int n, k, result = -1;

void bfs(int cur, int count){
	if(cur < 0 || (k<<1) <= cur) return;
	if(visited[cur] != 0 && visited[cur] <= count) return;
	visited[cur] = count;

	bfs(cur<<1, count+1);
	bfs(cur-1, count+1);
	bfs(cur+1, count+1);
}

int main(){
	scanf("%d %d", &n, &k);
		
	bfs(n, 0);

	printf("%d\n", visited[k]);

	return 0;
}
