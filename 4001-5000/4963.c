#include <stdio.h>

int result;
int map[51][51];
int visited[51][51];
int w, h;

int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int dy[] = { 1, 0, -1, 0, 1, 1, -1, -1 };

void sub_solution(int x, int y){
	visited[x][y] = 1;

	for(int i = 0; i < 8; i ++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(nx < 0 || w <= nx) continue;
		if(ny < 0 || h <= ny) continue;
		
		if(map[nx][ny] == 1 && visited[nx][ny] == 0) sub_solution(nx, ny);
	}
	return;
}

void solution(){
	for(int i = 0; i < w; i ++){
		for(int j = 0; j < h; j ++){
			if(visited[i][j] == 0 && map[i][j] == 1){
				sub_solution(i, j);
				result ++;
			}

		}
	}

}

int main(){
	while(scanf("%d %d", &w, &h) && ( w != 0 && h != 0)){
		result = 0;
		for(int i = 0; i < h; i ++){
			for(int j = 0; j < w; j ++){
				scanf("%d", map[j]+i);
				visited[j][i] = 0;
			}

		}

		solution();

		printf("%d\n", result);
	}
	

	return 0;
}
