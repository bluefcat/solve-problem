#include <cstdio>
#include <queue>
#include <utility>

using std::queue;
using pair = std::pair<int, int>;

constexpr int N = 601;

int main(){
	char field[N][N] = { 0, };
	bool check[N][N] = { false, };
	pair moving[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	int n, m;
	scanf("%d %d", &n, &m);
	
	queue<pair> q{};

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			char x;
			scanf(" %c", &x);
			field[i][j] = x;
			if(x == 'I'){ 
				q.push({j, i});
				check[i][j] = true; 
			}
		}
	}
	
	int result = 0;
	
	while(!q.empty()){
		auto [cx, cy] = q.front(); q.pop();

		for(auto [dx, dy]: moving){
			int nx = cx+dx, ny = cy+dy;
			if(!(0 <= nx && nx < m)) continue;
			if(!(0 <= ny && ny < n)) continue;
			if(field[ny][nx] == 'X') continue;
			if(check[ny][nx]) continue;
			
			result += (field[ny][nx] == 'P');
			q.push({nx, ny});
			check[ny][nx] = true;
		}
	}


	if(result == 0){
		printf("TT\n");
		return 0;
	}
	printf("%d\n", result);

	return 0;
}

