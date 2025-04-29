#include <cstdio>
#include <array>
#include <vector>
#include <tuple>
#include <queue>
#include <utility>
#include <algorithm>

using std::array;
using std::vector;
using std::tuple;
using cord = std::pair<int, int>;
constexpr int N = 11;

enum Direction{
	UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3
};

vector<tuple<Direction, int, int>> mov{
	{UP, -1, 0}, {DOWN, 1, 0}, {LEFT, 0, -1}, {RIGHT, 0, 1}
};

struct Vertex{
	int px = 0, py = 0;
	int color = 0;
	int area = 0;
	int number = -1;
	Vertex* next[4];
};

Vertex* field[N][N];
char board[2*N+2][2*N+2];

array<vector<cord>, 2> get_blocks(
	int area,
	Vertex* start,
	bool visited[][N]
){
	array<vector<cord>, 2> result;
	std::queue<Vertex*> q{{start}};
	result[start->color].push_back({start->py, start->px});
	visited[start->py][start->px] = true;
	start->area = area;
	
	while(!q.empty()){
		Vertex* cur = q.front(); q.pop();
		for(auto* next: cur->next){
			if(!next) continue;
			if(visited[next->py][next->px]) continue;
			
			q.push(next);
			result[next->color].push_back({next->py, next->px});
			visited[next->py][next->px] = true;
			next->area = area;
		}
	}
	return result;
}

void move_origin(vector<cord>& vec){
	int my = N+1, mx = N+1;
	for(auto [y, x]: vec){
		my = std::min(y, my);
		mx = std::min(x, mx);
	}	

	for(auto& p: vec){
		auto [y, x] = p;
		p = {y - my, x - mx};
	}
}

void rotate(vector<cord>& vec){
	for(auto& p: vec){
		auto [y, x] = p;
		p = {-x, y};
	}
}

void flip(vector<cord>& vec){
	for(auto& p: vec){
		auto [y, x] = p;
		p = {y, -x};
	}
}

bool check_shape(vector<cord>& white, vector<cord>& gray){
	move_origin(gray);

	bool shape[N][N] = { false, };
	for(auto [y, x]: gray) shape[y][x] = true;
	for(int f = 0; f < 2; f ++){
		for(int r = 0; r < 5; r ++){
			move_origin(white);
			bool checker = true;
			for(auto [y, x]: white){
				if(shape[y][x] == false) checker = false;				
			}
			if(checker) return true;
			
			rotate(white);
		}
		flip(white);
		move_origin(white);
	}

	return false;
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
		field[r-1][c-1]->number = x;
	}

	for(int i = 0; i < 2*n+1; i ++){
		scanf("%s", board[i]);
	}
	

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

	vector<array<vector<cord>, 2>> bucket{};

	int area = 0;
	int result = 1;

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(visited[i][j]) continue;
			bucket.emplace_back(get_blocks(area, field[i][j], visited));
			area ++;
		}
	}

	for(int i = 0; i < N*N; i ++) visited[i/N][i%N] = false;

	for(auto& blocks: bucket){
		auto& [white, gray] = blocks;
		//area check
		int number = -1;
		for(auto& block: blocks){
			for(auto [y, x]: block){
				Vertex* cur = field[y][x];
				if(number == -1 && cur->number != -1)
					number = cur->number;
				else if(number != -1 && cur->number != -1)
					result --;
			}
		}

		if(white.size() != gray.size())
			result --;

		if(number != -1 && (white.size() != number || gray.size() != number))
			result --;

		//two area check
		if(white.size() == 0 || gray.size() == 0)
			result --;

		//split check
		for(auto& block: blocks){
			if(block.size() == 0) break;
			auto [y, x] = block[0];
			Vertex* start = field[y][x];
			vector<Vertex*> tmp{};

			std::queue<Vertex*> q{{start}};
			visited[start->py][start->px] = true;
			tmp.push_back(start);
			while(!q.empty()){
				Vertex* cur = q.front(); q.pop();
				for(auto next: cur->next){
					if(!next) continue;
					if(visited[next->py][next->px]) continue;
					if(start->color != next->color) continue;
					q.push(next);
					visited[next->py][next->px] = true;
					tmp.push_back(next);
				}
			};

			if(block.size() != tmp.size())
				result --;
		}


		//wall check
		for(auto& block: blocks){
			for(auto [y, x]: block){
				Vertex* cur = field[y][x];
				for(auto [dir, dy, dx]: mov){
					if(!(0 <= x+dx && x+dx < n)) continue;
					if(!(0 <= y+dy && y+dy < n)) continue;

					Vertex* next = field[y+dy][x+dx];
					if(
						next->area == cur->area && 
						cur->next[dir] == nullptr
					) result --;
				}
			}
		}

		//shape check
		if(!check_shape(white, gray))
			result --;
	}

	printf("%d\n", result != 1? 0: 1);

	for(int i = 0; i < N*N; i ++)
		delete field[i/N][i%N];
	return 0;
}
