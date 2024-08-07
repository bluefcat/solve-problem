#include <cstdio>
#include <vector>
#include <unordered_map>

using std::vector;
using std::pair;
using std::unordered_map;

constexpr int N = 300001;

template<typename T>
int dfs(T& graph, int cur, int idx){
	for(auto [next, c]: graph[cur]){
		if(idx < c)
			return dfs(graph, next, c);
	}
	return cur;
}

int main(){
	unordered_map<int, vector<pair<int, int>>> graph{};
	bool check[N] = { false, };
	int n, m;

	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back({v, i+1});
	}
	
	for(int i = 1; i <= n; i ++){
		printf("%d ", dfs(graph, i, 0));
	}
	printf("\n");
	return 0;
}
