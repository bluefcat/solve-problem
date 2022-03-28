#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int arr[5][5];
int visited[5][5];

int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

int n, m;
int tmp, result;

int solve(int x, int y){
	int r = 0;
	int s = 0;
	visited[x][y] = 1;

	for(int i = 0; i < 4; i ++){
		int ax = x + dx[i], ay = y + dy[i];
		int bx = x + dx[(i+1)%4], by = y + dy[(i+1)%4];
		
		if((ax < 0 || n <= ax) || (bx < 0 || n <= bx)) continue;
		if((ay < 0 || m <= ay) || (by < 0 || m <= by)) continue;
		if(visited[ax][ay] || visited[bx][by]) continue;
		
		visited[ax][ay] = 1;
		visited[bx][by] = 1;
		
		s = 2*arr[x][y] + arr[ax][ay] + arr[bx][by];

		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				if(visited[i][j]) continue;
				r = MAX(r, s + solve(i, j));
			}
		}

		visited[ax][ay] = 0;
		visited[bx][by] = 0;
	}

	visited[x][y] = 0;
	
	if(s != 0 && r != 0) return r;
	if(s != 0 && r == 0) return s;
	return r;
}


int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++) scanf("%d", arr[i]+j);

	int a = solve(0, 0);
	result = (a, result);

	printf("%d\n", result);

	return 0;
}
