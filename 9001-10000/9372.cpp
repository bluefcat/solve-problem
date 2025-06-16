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
	int y,
    int cost,
    int& result
){
	int px = find(u, x);
	int py = find(u, y);
    if(px == py) return;
    result += cost;
	if(px < py){
		u[py] = px;
		return;
	}
	u[px] = py;
}

int main(){
	int t= 0;
	scanf("%d", &t);
	while(t--){
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
			int a, b;
			scanf("%d %d", &a, &b);
			connect[a][b] = 1;
			connect[b][a] = 1;
			candidate.push(std::make_tuple(a, b, 1));
		}
		while(!candidate.empty()){
			//top's type is const std::tuple&
			auto t = candidate.top();
			int x = std::get<0>(t);
			int y = std::get<1>(t);
			int cost = std::get<2>(t);
			combine(u, x, y, cost, result);

			candidate.pop();
		}
		printf("%d\n", result);
	}

	return 0;
}
