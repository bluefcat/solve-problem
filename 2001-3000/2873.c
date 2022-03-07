#include <stdio.h>

char w[] = {'R', 'D', 'L', 'U'};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int map[1001][1001];
int visited[1001][1001];
int R, C, result;

char route[1001*1001];

int main(){
	scanf("%d %d", &R, &C);

	for(int i = 0; i < R; i ++){
		for(int j = 0; j < C; j ++) scanf("%d", map[i] + j);
	}

	int x = 0, y = 0;

	while(x != R-1 && y != C-1){
		visited[x][y] = 1;

		int cnt = 0;
		int nx = x, ny = y;
		char a = ' ';
		for(int i = 0; i < 4; i ++){
			int tnx = x + dx[i], tny = y + dy[i];
			
			if(tnx < 0 || R <= tnx) continue;
			if(tny < 0 || C <= tny) continue;

			if(visited[tnx][tny]) continue;
	
			if(cnt == 0){
				nx = tnx; ny = tny;
				a = w[i];
				cnt ++;
			}
			else{
				if(map[nx][ny] < map[tnx][tny]){
					nx = tnx; ny = tny;
					a = w[i];
				}
			}
		}
		route[result++] = a;
		if(nx == x && ny == y) break;
		x = nx; y = ny;
	}
	
	for(int i = 0; i < result; i ++) printf("%c", route[i]);
	printf("\n");

	return 0;
}
