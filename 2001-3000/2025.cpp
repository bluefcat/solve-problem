#include <cstdio>
#include <stack>
#include <tuple>
#include <algorithm>


constexpr int N = 667;

using cond = std::pair<int, int>;
using std::stack;
using std::tuple;

bool compare(
	std::tuple<cond, int, int>& x,
	std::tuple<cond, int, int>& y
) {
	if(std::get<1>(x) == std::get<1>(y))
		return std::get<2>(x) > std::get<2>(y);
	return std::get<1>(x) < std::get<1>(y);
}


bool visited[N][N] = { 0, };
int degrees[N][N] = { 0, };
cond moving[8] = {
	{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
	{1, -2}, {1, 2}, {2, -1}, {2, 1}
};

inline constexpr int euclidean(int x, int y, int nx, int ny){
	return (x-nx)*(x-nx)+(y-ny)*(y-ny);
}

int degree(int n, int x, int y){
	int result = 0;
	for(auto [dx, dy]: moving){
		if(!(1 <= x+dx && x+dx <= n) ||
		   !(1 <= y+dy && y+dy <= n)) continue;
		result += !visited[x+dx][y+dy];
	}
	return result;
}

bool is_done(int n){
	bool result = true;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			result &= visited[i][j];
		}
	}
	return result;
}

int solving(int n, int x, int y, stack<cond>& record, int c){
	visited[x][y] = true;
	record.push({x, y});

	if(degree(n, x, y) <= 0){
		if(c == n*n && is_done(n)) return true;
		visited[x][y] = false;
		record.pop();
		return false;
	}
	
	bool result = false;
	
	tuple<cond, int, int> arr[8] = {};
	int idx = 0;

	for(auto [dx, dy]: moving){
		int nx = x+dx, ny = y+dy;
		if(!(1 <= nx && nx <= n) || !(1 <= ny && ny <= n)) continue;
		if(visited[nx][ny]) continue;
		degrees[nx][ny] -= 1;
		arr[idx++] = {{nx, ny}, degrees[nx][ny], euclidean(n/2, n/2, nx, ny)};
	}

	std::sort(arr, arr+idx, compare);

	for(int i = 0; i < idx; i ++){
		auto [pos, deg, dis] = arr[i];
		auto [nx, ny] = pos;
		result |= solving(n, nx, ny, record, c+1);
		if(result) break;
	}


	if(result) return result;	
	visited[x][y] = false;
	record.pop();
	for(auto [dx, dy]: moving){
		int nx = x+dx, ny = y+dy;
		if(!(1 <= nx && nx <= n) || !(1 <= ny && ny <= n)) continue;
		if(visited[nx][ny]) continue;
		degrees[nx][ny] += 1;
	}
	return result;
}


int main(){
	int n, x, y;
	
	scanf("%d %d %d", &n, &x, &y);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			degrees[i][j] = degree(n, i, j); 
	stack<cond> record{};
	//bool a = solving(n, x, y, record, 1);
	
	record.push({x, y});
	for(int i = 1; i <= n*n; i ++){
		auto [cx, cy] = record.top();
		visited[cx][cy] = true;
		tuple<cond, int, int> arr[8] = {};
		int idx = 0;
		for(auto [dx, dy]: moving){
			int nx = cx+dx, ny = cy+dy;
			if(!(1 <= nx && nx <= n) || !(1 <= ny && ny <= n)) continue;
			if(visited[nx][ny]) continue;
			
			arr[idx++] = {{nx, ny}, degree(n, nx, ny), euclidean(n, n, nx*2, ny*2)};
		}
		std::sort(arr, arr+idx, compare);
		if(i == n*n) break;
		record.push({std::get<0>(arr[0]).first, std::get<0>(arr[0]).second});
	}
	bool a = is_done(n);

	if(!a){
		printf("-1 -1\n");
		return 0;
	}
	stack<cond> result{};
	while(!record.empty()){
		auto [x, y] = record.top(); record.pop();
		result.push({x, y});
	}
	while(!result.empty()){
		auto [x, y] = result.top(); result.pop();
		printf("%d %d\n", x, y);
	}
	
	return 0;
}
