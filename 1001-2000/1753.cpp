#include <cstdio>
#include <unordered_map>
#include <queue>

#define N 200001

struct pair_less{
	bool operator()(
		const std::pair<int, int>& x,
		const std::pair<int, int>& y
	){
		return x.second > y.second;
	}
};

int main(){
	std::unordered_map<
		int,
		std::unordered_map<int, int>
	> graph;

	std::priority_queue<
		std::pair<int, int>,
		std::vector<std::pair<int, int>>,
		pair_less
	> q;	
	
	int result[N] = { 0, };
	for(int i = 2; i < N; i ++) result[i] = -1;

	int v, e, k;
	scanf("%d %d %d", &v, &e, &k);
	for(int i = 0; i < e; i ++){
		int x, y, cost;
		scanf("%d %d %d", &x, &y, &cost);
		if(graph[x][y]) graph[x][y] = std::min(cost, graph[x][y]);
		else graph[x][y] = cost;
	}

	q.push(std::make_pair(k, 0));

	while(!q.empty()){
		const auto& p = q.top();
		int x = p.first;
		int c = p.second;
		
		if(result[x] != -1 && result[x] < c){
			q.pop();
			continue;
		}

		for(const auto& [y, cost]: graph[x]){
			if(result[y] == -1 || c+cost < result[y]){
				result[y] = c+cost;
				q.push(std::make_pair(y, c + cost));
			}
		}
		q.pop();
	}
	
	for(int i = 1; i <= v; i ++){
		if(result[i] == -1){
			printf("INF\n");
			continue;
		}
		printf("%d\n", result[i]);
	}
	return 0;
}
