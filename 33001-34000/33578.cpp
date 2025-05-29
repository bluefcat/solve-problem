#include <cstdio>
#include <queue>
#include <climits>

using lint = long long;
constexpr int N = 3001;

char field[N][N] ={ 0, };
lint visited[N][N] = { false, };

std::vector<std::tuple<lint, lint>> mov{
	{1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

std::queue<std::tuple<lint, lint, lint, lint>> q{};	

int main(){
	lint n, m;
	n = 3000; m = 3000;
	//scanf("%lld %lld", &n, &m);

	lint px = 0, py = 0;
	lint ex = 0, ey = 0;

	for(int i = 0; i < n; i ++){
		//scanf("%s", field[i]);
		for(int j = 0; j < m; j ++){
			if(i == 0 && j == 0) field[i][j] = 'S';
			if(i == n-1 && j == m-1) field[i][j] = 'J';
			//if(i == n/2 && j == m/2 ) field[i][j] = 'T';
			if(field[i][j] == 'J'){
				px = j; py = i;
			}
			else if(field[i][j] == 'S'){
				ex = j; ey = i;
			}
		}
	}

	q.push({px, py, 2, 0});
	visited[py][px] = 0;
	lint result = 0;
	
	while(!q.empty()){
		auto [cx, cy, dt, t] = q.front(); q.pop();	

		for(auto [dx, dy]: mov){
			lint nx = cx + dx, ny = cy + dy;
			if(!(0 <= nx && nx < m)) continue;
			if(!(0 <= ny && ny < n)) continue;
			if(field[ny][nx] == '#') continue;
			
			int ndt = dt;
			if(field[ny][nx] == 'T') ndt = 1;
			if(visited[ny][nx] < t+dt || (visited[ny][nx] == t+dt && dt <= ndt)) continue;

			q.push({nx, ny, ndt, t+dt});
			visited[ny][nx] = t+dt;
			if(nx == ex && ny == ey){
				if(result == -1) result = t+dt;
				result = (result > t+dt)?(t+dt):result;
			}
		}

	}
	
	printf("%lld\n", result);

	return 0;
}
