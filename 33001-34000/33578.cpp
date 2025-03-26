#include <cstdio>
#include <queue>
#include <climits>

using lint = long long;
constexpr int N = 3001;

char field[N][N] ={ 0, };
bool visited[N][N] = { false, };

std::vector<std::tuple<lint, lint>> mov{
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

std::queue<std::tuple<lint, lint, lint, lint>> q{};	

int main(){
	lint n, m;
	scanf("%lld %lld", &n, &m);

	lint px = 0, py = 0;
	lint ex = 0, ey = 0;

	for(int i = 0; i < n; i ++){
		scanf("%s", field[i]);
		for(int j = 0; j < m; j ++){
			if(field[i][j] == 'J'){
				px = j; py = i;
			}
			else if(field[i][j] == 'S'){
				ex = j; ey = i;
			}
		}
	}

	q.push({px, py, 2, 0});
	visited[py][px] = true;
	lint result = ;
	
	while(!q.empty()){
		auto [cx, cy, dt, t] = q.front(); q.pop();	

		for(auto [dx, dy]: mov){
			lint nx = cx + dx, ny = cy + dy;
			if(!(0 <= nx && nx < m)) continue;
			if(!(0 <= ny && ny < n)) continue;
			if(field[ny][nx] == '#') continue;
			if(visited[ny][nx]) continue;
			
			int ndt = dt;
			if(field[ny][nx] == 'T') ndt = 1;

			q.push({nx, ny, ndt, t+dt});
			if(nx == ex && ny == ey){
				result = (result > t+dt)?(t+dt):result;
			}
		}

	}
	
	printf("%lld", result);

	return 0;
}
