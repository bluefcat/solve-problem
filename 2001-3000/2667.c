#include <stdio.h>
#include <stdlib.h>

int map[26][26];
int apart[625];
int count;
int visited[26][26];

int compare(const void* x, const void* y){
	return *(int*)x - *(int*)y;
}

void countApart(int n, int x, int y){
	apart[count] ++;
	visited[x][y] = 1;
	
	if(0 <= x-1) if(visited[x-1][y] == 0 && map[x-1][y] == 1) countApart(n, x-1, y);
	if(x+1 < n)  if(visited[x+1][y] == 0 && map[x+1][y] == 1) countApart(n, x+1, y);
	if(0 <= y-1) if(visited[x][y-1] == 0 && map[x][y-1] == 1) countApart(n, x, y-1);
	if(y+1 < n)  if(visited[x][y+1] == 0 && map[x][y+1] == 1) countApart(n, x, y+1);
	
	return;
}

int main(){
	int N;
	scanf("%d", &N);

	for(int i = 0; i < N; i ++){
		for(int j = 0; j < N; j ++) scanf("%1d", map[i]+j);
	}
	
	for(int i = 0; i < N; i ++){
		for(int j = 0; j < N; j ++) {
			if(visited[i][j] == 0 && map[i][j] == 1){
				countApart(N, i, j);
				count ++;
			}
		}
	}

	qsort(apart, count, sizeof(int), compare);

	printf("%d\n", count);
	for(int i = 0; i < count; i ++) printf("%d\n", apart[i]);

	return 0;
}
