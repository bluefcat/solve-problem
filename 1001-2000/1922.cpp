#include <cstdio>
#include <map>
#include <queue>
#include <tuple>

struct compare{
	bool operator()(
		std::tuple<int, int, int> x,
		std::tuple<int, int, int> y
	){
		return std::get<2>(x) > std::get<2>(y);
	}
};

int find(std::map<int, int>& u, int x){
	if(u[x] == x) return x;
	return u[x] = find(u, u[x]);
}

void combine(
	std::map<int, int>& u,
	int x,
	int y
){
	int px = find(u, x);
	int py = find(u, y);
	if(px < py){
		u[py] = px;
		return;
	}
	u[px] = py;
}

static inline bool is_combine(
	std::map<int, int>& u,
	int x,
	int y
){
	return u[x] == u[y];
}

int main(){
	int n, m, result = 0;
	std::map<int, int> u;
	std::map<
		int, std::map<int, int>
	> connect;
	std::priority_queue<
		std::tuple<int, int, int>,
		std::vector<std::tuple<int, int, int>>,
		compare
	> candidate;
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 0; i <= n; i ++) u[i] = i;

	for(int i = 0; i < m; i ++){
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		connect[a][b] = cost;
		connect[b][a] = cost;
		candidate.push(std::make_tuple(a, b, cost));
	}
	while(!candidate.empty()){
		//top's type is const std::tuple&
		auto t = candidate.top();
		int x = std::get<0>(t);
		int y = std::get<1>(t);
		int cost = std::get<2>(t);
		if(!is_combine(u, x, y)){
			result += cost;
			combine(u, x, y);
		}
		candidate.pop();
	}
	printf("%d\n", result);

	return 0;
}
