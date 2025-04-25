#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>

constexpr int N = 11;

enum Direction{
	UP = 0, DOWN, LEFT, RIGHT
};

struct Vertex{
	int px = 0, py = 0;
	int color = 0;
	int x = -1;
	Vertex* next[4];
};

Vertex* field[N][N];
char board[2*N+2][2*N+2];

int main(){
	for(int i = 0; i < N*N; i ++)
		field[i/N][i%N] = new Vertex{i%N, i/N};
	
	int n = 0, k;
	scanf("%d", &n);
	for(int i = 0; i < n-1; i ++){
		for(int j = 0; j < n; j ++){
			field[j][i]->next[RIGHT] = field[j][i+1];
			field[j][i+1]->next[LEFT]  = field[j][i];
		}
	}

	for(int i = 0; i < n-1; i ++){
		for(int j = 0; j < n; j ++){
			field[i][j]->next[DOWN] = field[i+1][j];
			field[i+1][j]->next[UP]  = field[i][j];
		}
	}

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			scanf("%d", &(field[i][j]->color));
		}
	}

	scanf("%d", &k);
	for(int i = 0; i < k; i ++){
		int r, c, x;
		scanf("%d %d %d", &r, &c, &x);
		field[r-1][c-1]->x = x;
	}

	for(int i = 0; i < 2*n+1; i ++){
		scanf("%s", board[i]);
	}
	
	std::vector<std::tuple<Direction, int, int>> mov{
		{UP, -1, 0}, {DOWN, 1, 0}, {LEFT, 0, -1}, {RIGHT, 0, 1}
	};


	for(int i = 1; i < 2*n+1; i += 2){
		for(int j = 1; j < 2*n+1; j +=2){
			Vertex* n = field[i >> 1][j >> 1];
			for(auto& [dir, dy, dx]: mov){
				if(board[i+dy][j+dx] != '.')
					n->next[dir] = nullptr;
			}
		}
	}

	bool visited[N][N] = { 0, };
	bool flag = true;	
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(visited[i][j]) continue;

			std::queue<Vertex*> q({field[i][j]});
			visited[i][j] = true;

			int w = 0, b = 0, n = -1;
			
			while(!q.empty()){
				Vertex* cur = q.front(); q.pop();
				if(cur->color) b++;
				else w ++;
				if(n == -1){
					n = cur->x;
				}
				else if(n != -1 && cur->x != -1){
					flag &= false;	
				}	
				for(auto& [dir, dx, dy]: mov){
					Vertex* n = cur->next[dir];
					if(n == nullptr) continue;	
					if(visited[n->py][n->px]) continue;
					visited[n->py][n->px] = true;
					q.push(n);
				}
			}
			if(w != b){
				flag &= false;
			}
			if(n != -1 && (w != n || b != n)){
				flag &= false;
			}
		}
	}
	printf("%d\n", flag);

	for(int i = 0; i < N*N; i ++)
		delete field[i/N][i%N];
	return 0;
}
