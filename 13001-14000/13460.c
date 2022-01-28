#include <stdio.h>

#define QSIZE 10001
#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int queue[QSIZE][3];

int head, tail;

int result = 11;

char map[11][11];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		scanf(" ");
		for(int j = 0; j < m; j ++){
			scanf("%c", map[i]+j);
			
			if(map[i][j] == 'R'){
				queue[tail][0] = i, queue[tail][1] = j, queue[tail][2] = 0;

				tail = (tail + 1) % QSIZE;
			}

		}
	}

	while(head != tail){
		int x = queue[head][0], y = queue[head][1], d = queue[head][2];
		head = (head + 1) % QSIZE;

		if(map[x][y] == 'O'){
			result = MIN(result, d);
		}

		for(int i = 0; i < 4; i ++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(map[nx][ny] != '#' && d <= 9){
				queue[tail][0] = nx, queue[tail][1] = ny, queue[tail][2] = d+1;
				tail = (tail + 1) % QSIZE;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}
