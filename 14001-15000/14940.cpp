#include <cstdio>
#include <queue>
#include <tuple>

using std::queue;

constexpr int N = 1001;

int m[N][N] = { 0, };
int r[N][N] = { 0, };
bool vi[N][N] = { false, };

int main(){
	
	int w, h;
	int sx = 0, sy = 0;
	scanf("%d %d", &h, &w);
	for(int y = 0; y < h; y ++){
		for(int x = 0; x < w; x ++){
			scanf("%d", m[y]+x); 
			if(m[y][x] == 2){
				sx = x; sy = y;
			}
		}
	}

	int v[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	queue<std::tuple<int, int, int>> q{};
	q.push(std::make_tuple(sx, sy, 0));
	vi[sy][sx] = true;
	
	while(!q.empty()){
		auto [x, y, c] = q.front(); q.pop();
		r[y][x] = c;
		for(int i = 0; i < 4; i ++){
			int dx = v[i][0], dy = v[i][1];
			int nx = x+dx, ny = y+dy;
			if(!(0 <= nx && nx <= w)) continue;
			if(!(0 <= ny && ny <= h)) continue;
			if(m[ny][nx] == 0) continue;
			if(vi[ny][nx]) continue;
			q.push(std::make_tuple(nx, ny, c+1));
			vi[ny][nx] = true;
		}
	}
	
	for(int y = 0; y < h; y ++){
		for(int x = 0; x < w; x ++){
			if(!(x == sx && y == sy) && (r[y][x] == 0 && m[y][x] == 1)){
				printf("-1 ");
			}
			else{
				printf("%d ", r[y][x]);
			}
		}
		printf("\n");
	}

	return 0;
}
