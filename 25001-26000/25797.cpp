#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
#include <utility>
#include <algorithm>

constexpr int N = 11;

enum Direction{
	UP = 0, DOWN, LEFT, RIGHT
};

struct Vertex{
	int px = 0, py = 0;
	int color = 0;
	int area = 0;
	int x = -1;
	Vertex* next[4];
};

Vertex* field[N][N];
char board[2*N+2][2*N+2];

void rotate(std::pair<int, int>& p){
	auto [y, x] = p;
	p = {-x, y};
}

void flip(std::pair<int, int>& p){
	auto [y, x] = p;
	p = {y, -x};
}

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
	int cnt = -1;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(visited[i][j]) continue;

			std::queue<Vertex*> q({field[i][j]});
			cnt ++;
			field[i][j]->area = cnt;
			visited[i][j] = true;

			int w = 0, b = 0, p = -1;
			Vertex* start_w = nullptr;
			Vertex* start_b = nullptr;

			std::pair<int, int> sw[2*N];
			std::pair<int, int> sb[2*N];
			
			while(!q.empty()){
				Vertex* cur = q.front(); q.pop();
				if(cur->color){ 
					if(!start_b) start_b = cur;
					sb[b] = {cur->py, cur->px};
					b++;
					
				}
				else{ 
					if(!start_w) start_w = cur;
					sw[w] = {cur->py, cur->px};
					w ++;
				}
				if(p == -1){
					p = cur->x;
				}
				else if(p != -1 && cur->x != -1){
					flag &= false;	
				}	
				for(auto& [dir, dx, dy]: mov){
					Vertex* nx = cur->next[dir];
					if(nx == nullptr) continue;	
					if(visited[nx->py][nx->px]) continue;
					visited[nx->py][nx->px] = true;
					nx->area=cnt;
					q.push(nx);
				}
			}


			if(w != b){
				flag &= false;
				break;
			}
			if(p != -1 && (w != p || b != p)){
				flag &= false;
				break;
			}
			
			int mx = 99, my = 99;
			for(int i = 0; i < w; i ++){
				my = std::min(sw[i].first, my);	
				mx = std::min(sw[i].second, mx);	
			}
			for(int i = 0; i < w; i ++){
				sw[i] = {sw[i].first - my, sw[i].second - mx};
			}

			
			bool same_shape = false;
			//check shape
			for(int f = 0; f < 2; f++){
				for(int r = 0; r < 5; r ++){
					int bp[N] = { 0, };	
					int mbx = 99, mby = 99;
					for(int i = 0; i < b; i ++){
						mby = std::min(sb[i].first, mby);	
						mbx = std::min(sb[i].second, mbx);	
					}
					for(int i = 0; i < b; i ++)
						sb[i] = {sb[i].first - mby, sb[i].second - mbx};
					
					int tcount = 0;
					for(int i = 0; i < b; i ++){
						bool tmp = false;
						for(int j = 0; j < w; j ++){
							if(sb[i].first == sw[j].first && sb[i].second == sw[j].second){
								tmp = true;
							}	
						}
						tcount += (int)tmp;
					}
					
					if(tcount == b) same_shape = true;
					for(int i = 0; i < b; i ++){
						rotate(sb[i]);
					}

				}

				for(int i = 0; i < b; i ++){
					flip(sb[i]);
				}
			}
			if(!same_shape){
				flag &= false;
				break;
			}
			
			bool shape_visited[2][N][N] = {false};
			int wsc = 1, bsc = 1;
			
			while(!q.empty()) q.pop();
			q.push(start_w);
			shape_visited[0][start_w->py][start_w->px] = true;
			while(!q.empty()){
				Vertex* cur = q.front(); q.pop();
				for(auto& [dir, dx, dy]: mov){
					Vertex* nx = cur->next[dir];
					if(nx == nullptr) continue;	
					if(shape_visited[0][nx->py][nx->px]) continue;
					if(nx->color != 0) continue;
					shape_visited[0][nx->py][nx->px] = true;
					wsc ++;
					q.push(nx);
				}
			}
			while(!q.empty()) q.pop();
			q.push(start_b);
			shape_visited[1][start_b->py][start_b->px] = true;
			while(!q.empty()){
				Vertex* cur = q.front(); q.pop();
				for(auto& [dir, dx, dy]: mov){
					Vertex* nx = cur->next[dir];
					if(nx == nullptr) continue;	
					if(shape_visited[1][nx->py][nx->px]) continue;
					if(nx->color != 1) continue;
					shape_visited[1][nx->py][nx->px] = true;
					bsc ++;
					q.push(nx);
				}
			}
			if(bsc != b || wsc != w){ 
				flag &= false;
				break;
			}

		}
	}
	for(int y = 0; y < n; y ++){
		for(int x = 0; x < n; x ++){
			Vertex* cur = field[y][x];
			for(auto& [dir, dy, dx]: mov){
				if(!(0 <= x+dx && x+dx < n) || !(0 <= y+dy && y+dy <n)) continue;
				if(
					(cur->area == field[y+dy][x+dx]->area) &&
					(cur->next[dir] == nullptr)
				){
					flag &= false;
					break;
				}
			}
		}
	}
	printf("%d\n", flag);

	for(int i = 0; i < N*N; i ++)
		delete field[i/N][i%N];
	return 0;
}
