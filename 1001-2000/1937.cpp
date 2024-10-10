#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>

using pair = std::pair<int, int>;
using queue = std::queue<pair>;

constexpr int N = 501;

int field[N][N] = { 0, };
int order[N][N] = { 0, };
int cache[N][N] = { 0, };

pair moving[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isin(int n, int x, int y){
	return (0 <= x && x < n) && (0 <= y && y < n);
}

int main(){
	int result = 1;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			scanf("%d", field[i] + j);
			cache[i][j] = 1;
		}
	}

	queue q{};

	for(int y = 0; y < n; y ++){
		for(int x = 0; x < n; x ++){
			for(auto& [dy, dx]: moving){
				int nx = x+dx, ny = y+dy;
				if(!isin(n, nx, ny)) continue;
				order[y][x] += (field[y][x] > field[ny][nx]); 
			}
			if(order[y][x] == 0){
				q.push({y, x});
			}
		}
	}

	for(int i = 0; i < n*n; i ++){
		auto [y, x] = q.front(); q.pop();
		for(auto& [dy, dx]: moving){
			int nx = x + dx, ny = y + dy;
			if(!isin(n, nx, ny)) continue;
			if(field[y][x] > field[ny][nx]) continue;
			cache[ny][nx] = std::max(
					cache[ny][nx], 
					cache[y][x] + 1
			);
			result = std::max(result, cache[ny][nx]);
			order[ny][nx] --;
			if(order[ny][nx] == 0)
				q.push({ny, nx});
		}
	}
	
	printf("%d\n", result);
	return 0;
}
