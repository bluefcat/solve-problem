#include <stdio.h>

#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int map[9][9];
int n, m;
int result;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

#define QSIZE 81
int queue[QSIZE][2];
int head, tail;

void solution(){
	int cmap[9][9];

	for(int i = 0; i < 9; i ++) for(int j = 0; j < 9; j ++) cmap[i][j] = map[i][j];


	for(int x = 0; x < n; x ++){
		for(int y = 0; y < m; y ++){
			if(cmap[x][y] != 2) continue;
			
			queue[tail][0] = x;
			queue[tail][1] = y;

			tail = (tail + 1) % QSIZE;
		}
	}


	while(head != tail){
		int cx = queue[head][0];
		int cy = queue[head][1];

		head = (head + 1) % QSIZE;


		for(int i = 0; i < 4; i ++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if(nx < 0 || n <= nx) continue;
			if(ny < 0 || m <= ny) continue;
			if(cmap[nx][ny] != 0) continue;

			cmap[nx][ny] = 2;

			queue[tail][0] = nx;
			queue[tail][1] = ny;

			tail = (tail + 1) % QSIZE;
		}

	}

	int cnt = 0;
	for(int i = 0; i < n; i ++) for(int j = 0; j < m; j ++) if(cmap[i][j] == 0) cnt ++;

	result = MAX(result, cnt);

	return;
}

void build_wall(int d){
	if(d == 3){
		solution();
		return;
	}
	
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			if(map[i][j]) continue;

			map[i][j] = 1;
			build_wall(d + 1);
			map[i][j] = 0;
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++) scanf("%d", map[i] + j);
	}
	build_wall(0);

	printf("%d\n", result);

	return 0;
}
