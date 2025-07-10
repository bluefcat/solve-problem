#include <cstdio>

constexpr int N = 65;
int board[N][N] = {};
bool win = false;

void solve(int n, int x, int y){
	if(board[x][y] == -1) win = true;
	if(win) return;
	
	int d = board[x][y];
	if(0 <= x+d && x+d < n) solve(n, x+d, y);
	if(0 <= y+d && y+d < n) solve(n, x, y+d);
	return;
}

int main(){
	int n;
	n=64;
	scanf("%d", &n);
	for(int y = 0; y < n; y ++)
		for(int x = 0; x < n; x ++)
			scanf("%d", board[y] + x);
	solve(n, 0, 0);
	if(win){
		printf("HaruHaru\n");
		return 0;
	}
	printf("Hing\n");
	return 0;
}
