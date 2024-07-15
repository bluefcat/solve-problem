#include <cstdio>
#include <cstdlib>
#include <queue>

const int N = 21;
using cord = std::pair<int, int>;

int move_cord[4][2] = {
	{0, -1}, {-1, 0}, {0, 1}, {1, 0}
};

std::pair<cord, int> find_path(int* arr, int s, int n, int x, int y){
	cord result{-1, -1};
	int dist = -1;
	bool check[N*N] = { 0, };
	std::queue<std::pair<cord, int>> q{};
	q.push({{y, x}, 0});
	check[y*n+x] = true;
	
	while(!q.empty()){
		auto p = q.front();
		int px = p.first.second;
		int py = p.first.first;
		int d = p.second;
		for(int i = 0; i < 4; i ++){
			int nx = px + move_cord[i][0];
			int ny = py + move_cord[i][1];

			if(!(0 <= nx && nx < n)) continue;
			if(!(0 <= ny && ny < n)) continue;
			if(check[ny*n+nx]) continue;

			if(arr[ny*n+nx] > s) continue;
			
			if(0 < arr[ny*n+nx] && arr[ny*n+nx] < s){
				if(dist == -1 || dist > d+1){
					dist = d+1;
					result = {ny, nx};
				}
				else if(dist == d+1){
					int ry = result.first;
					int rx = result.second;
					if(ry > ny){
						result = {ny, nx};
					}
					else if(ry == ny && rx > nx){
						result = {ny, nx};
					}
				}
			}

			q.push({{ny, nx}, d+1});
			check[ny*n+nx] = true;
		}
		q.pop();
	}
	return {result, dist};
}

int main(){
	int result = 0;
	int arr[N*N] = { 0, };	
	
	int n, s, x, y;
	scanf("%d", &n);

	for(int i = 0 ; i < n*n; i ++){
		scanf("%d", arr+i);
		if(arr[i] == 9){
			arr[i] = 0;
			x = i % n;
			y = i / n;
			s = 2;
		}
	}
	int dist = -1;
	int cnt = 0;
	while(true){
		auto p = find_path(arr, s, n, x, y);
		int nx = p.first.second;
		int ny = p.first.first;
		dist = p.second;
		if(dist == -1) break;
		result += dist;
		x = nx;
		y = ny;
		arr[ny*n+nx] = 0;
		cnt ++;
		if(cnt == s){
			s++;
			cnt = 0;
		}
	} 

	printf("%d\n", result);
	

	return 0;
}
