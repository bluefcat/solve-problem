#include <stdio.h>

char map[101][101];
int visited[101][101];
int sub_visited[101][101];

int n;
int result, sub_result;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void sub_solution(int x, int y, char target, int flag){
	if(x < 0 || n <= x) return;
	if(y < 0 || n <= y) return;
	
	if(flag) sub_visited[x][y] = 1;
	else visited[x][y] = 1;

	for(int i = 0; i < 4; i ++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(flag){
			if(sub_visited[nx][ny] == 0 && 
					((target == 'R' || target == 'G') && (map[nx][ny] == 'R' || map[nx][ny] == 'G') || 
					 (map[nx][ny] == target)
					 )
			  ){
				sub_solution(nx, ny, target, flag);
			}

		}

		else if(visited[nx][ny] == 0 && map[nx][ny] == target){
			sub_solution(nx, ny, target, flag);
		}
	}

	return;
}

void solution(){
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(visited[i][j] == 0){
				sub_solution(i, j, map[i][j], 0);
				result ++;
			}
			if(sub_visited[i][j] == 0){
				sub_solution(i, j, map[i][j], 1);
				sub_result ++;
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf(" ");
		for(int j = 0; j < n; j ++) scanf("%1c", map[i]+j);
	}
		
	solution();

	printf("%d %d\n", result, sub_result);

	return 0;
}
