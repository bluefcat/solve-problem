#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int map[501][501];
int n, m;

int result;

int visited[501][501];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int stack[100][2];

void search(int x, int y, int e, int d){
	if(visited[x][y]) return;
	if(x < 0 || n <= x) return;
	if(y < 0 || m <= y) return;
	
	stack[d][0] = x; stack[d][1] = y;

	if(d == 3){
		result = MAX(result, e);
		return;
	}
	
	visited[x][y] = 1;
	for(int i = 0; i < 4; i ++){
		search(x+dx[i], y+dy[i], e+map[x+dx[i]][y+dy[i]], d+1);
	}

	visited[x][y] = 0;
	return ;
}

int main(){
	scanf("%d %d", &n, &m);	
	
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++) scanf("%d", map[i]+j);

	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++) search(i, j, map[i][j], 0);

	printf("%d\n", result);

	return 0;
}
