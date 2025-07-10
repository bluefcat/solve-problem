#include <cstdio>

constexpr int N = 65;
int board[N][N] = {};
bool visit[N][N] = {};
bool win = false;

void solve(int n, int x, int y){
	if(board[y][x] == -1){ 
		win = true;
	}
	
	int d = board[y][x];
	if(0 <= x+d && x+d < n && !visit[y][x+d] && !win){ 
		visit[y][x+d] = true;
		solve(n, x+d, y);
	}
	if(0 <= y+d && y+d < n && !visit[y+d][x] && !win){ 
		visit[y+d][x] = true;
		solve(n, x, y+d);
	}
	return;
}

int main(){
	int n;
	n=64;
	scanf("%d", &n);
	for(int y = 0; y < n; y ++)
		for(int x = 0; x < n; x ++)
			scanf("%d", board[y] + x);

	visit[0][0] = true;
	solve(n, 0, 0);

	if(win){
		printf("HaruHaru\n");
		return 0;
	}
	printf("Hing\n");
	return 0;
}
