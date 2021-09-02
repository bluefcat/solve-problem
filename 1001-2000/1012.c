#include <stdio.h>

int field[50][50];
int visited[50][50];

void init(){
	for(int i = 0; i < 50; i ++){
		for(int j = 0; j < 50; j ++){
			field[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void DFS(int x, int y, int n, int m){
	if(field[x][y] == 0 || visited[x][y] == 1) return;
	visited[x][y] = 1;
	
	if(x-1 >= 0) DFS(x-1, y, n, m);
	if(x+1 < n)  DFS(x+1, y, n, m);
	if(y-1 >= 0)  DFS(x, y-1, n, m);
	if(y+1 < m)  DFS(x, y+1, n, m);
}

int main(){
	
	int n = 0, m = 0, k = 0, t = 0;
	
	scanf("%d", &t);

	for(int a = 0; a < t; a ++){
		init();
		int result = 0;
		scanf("%d %d %d", &n, &m, &k);
			
		for(int i = 0; i < k; i ++){
			int x = 0, y = 0;
			scanf("%d %d", &x, &y);
			field[x][y] = 1;
		}

		for(int i = 0; i < n; i ++){
			for(int j = 0; j < m; j ++){
				if(visited[i][j] == 0 && field[i][j] == 1){
					DFS(i, j, n, m);
					result ++;
				}
			}
		}

		printf("%d\n", result);
	}
	return 0;
}
