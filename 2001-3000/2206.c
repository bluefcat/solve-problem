#include <stdio.h>
#define MIN(X, Y) (((X) > (Y))? (Y): (X))

#define QMAX 1000001

int cache[1001][1001];
int queue[QMAX][3];
int head, length;
int visited[1001][1001][2];
int n, m;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int find(int x, int y){
	int b = 1;

	queue[0][0] = x;
	queue[0][1] = y;
	queue[0][2] = b;
	visited[x][y][b] = 1;
	head = 0;
	length = (length+1)%QMAX;

	while(head != length){
		x = queue[head][0];
		y = queue[head][1];
		b = queue[head][2];
		head = (head + 1)%QMAX;

		if(x == n-1 && y == m-1){
			return visited[x][y][b];
		}
		
		for(int i = 0; i < 4; i ++){
			if(dx[i] + x < 0 || n <= dx[i] + x) continue;
			if(dy[i] + y < 0 || m <= dy[i] + y) continue;
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			int pb = b;
			
			if(cache[nx][ny] == 1 && pb == 1){
				visited[nx][ny][pb-1] = visited[x][y][pb] + 1;
				pb = pb-1;
				goto PUSH;
			}
			else if(cache[nx][ny] == 0 && visited[nx][ny][pb] == 0){
				visited[nx][ny][pb] = visited[x][y][pb] + 1;
				goto PUSH;
			}
			
			goto END;

			PUSH:
			//push queue
			queue[length][0] = nx;
			queue[length][1] = ny;
			queue[length][2] = pb;
				
			length = (length + 1)%QMAX;
			END:
			continue;
		}
	}
	return -1;
}


int main(){
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++) scanf("%1d", cache[i]+j);
	}
	
	int result = find(0, 0);

	printf("%d\n", result);

	return 0;
}
