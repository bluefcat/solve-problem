#include <stdio.h>
#define ABS(X) (((X) > 0)? (X): -(X))
#define QMAX 1000

typedef struct _Point{
	int x;
	int y;
} Point;

int maze[100][100];
int visited[100][100];
Point queue[QMAX];

void BFS(int n, int m){
	int head = 0;
	int tail = 0;

	queue[tail].x = 0; queue[tail].y = 0;
	tail = (tail + 1) % QMAX;
	visited[0][0] = 1;

	while(ABS(tail - head) > 0){
		int cx = queue[head].x, cy = queue[head].y;
		head = (head + 1) % QMAX;

		if(cx-1 >= 0)		
		if(maze[cx-1][cy] == 1 && visited[cx-1][cy] == 0){
			queue[tail].x = cx-1; queue[tail].y = cy;
			tail = (tail + 1) % QMAX;
			visited[cx-1][cy] = 1;
			maze[cx-1][cy] = maze[cx][cy]+1;
		}

		if(cy-1 >= 0)
		if(maze[cx][cy-1] == 1 && visited[cx][cy-1] == 0){
			queue[tail].x = cx; queue[tail].y = cy-1;
			tail = (tail + 1) % QMAX;
			visited[cx][cy-1] = 1;
			maze[cx][cy-1] = maze[cx][cy]+1;
		}
		if(cx+1 < n)
		if(maze[cx+1][cy] == 1 && visited[cx+1][cy] == 0){
			queue[tail].x = cx+1; queue[tail].y = cy;
			tail = (tail + 1) % QMAX;
			visited[cx+1][cy] = 1;
			maze[cx+1][cy] = maze[cx][cy]+1;
		}
		if(cy+1 < m)
		if(maze[cx][cy+1] == 1 && visited[cx][cy+1] == 0){
			queue[tail].x = cx; queue[tail].y = cy+1;
			tail = (tail + 1) % QMAX;
			visited[cx][cy+1] = 1;
			maze[cx][cy+1] = maze[cx][cy]+1;
		}
	}

	return ;
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i ++){
		for(int j = 0; j < M; j ++) scanf("%1d", maze[i]+j);
	}
	
	BFS(N, M);

	printf("%d\n", maze[N-1][M-1]);
	return 0;
}
