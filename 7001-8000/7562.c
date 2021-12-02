#include <stdio.h>

#define QMAX 90601 

int queue[QMAX][2];
int head, tail;

int visited[301][301];

int n;
int cx, cy;
int px, py;

int dx[] = { 1, 2, -1, -2, 1, 2, -1, -2 };
int dy[] = { 2, 1, 2, 1, -2, -1, -2, -1 };

void push_back(int x, int y){
	queue[tail][0] = x;
	queue[tail][1] = y;

	tail = (tail + 1)%QMAX;
}

void pop(){
	head = (head + 1)%QMAX;
}

int solve(){
	//init
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++) visited[i][j] = 0;
	}
	head = 0;
	tail = 0;
	push_back(cx, cy);
	visited[cx][cy] = 1;

	while(head != tail){
		int x = queue[head][0];
		int y = queue[head][1];
		pop();
		
		if(x == px && y == py) return visited[x][y];

		for(int i = 0; i < 8; i ++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx < 0 || n <= nx) continue;
			if(ny < 0 || n <= ny) continue;

			if(visited[nx][ny] > 0) continue;

			visited[nx][ny] = visited[x][y] + 1;
			
			push_back(nx, ny);
		}
	}
	return 0;
}

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		scanf("%d %d", &cx, &cy);
		scanf("%d %d", &px, &py);
		
		printf("%d\n", solve()-1);
	}
	
	return 0;
}
