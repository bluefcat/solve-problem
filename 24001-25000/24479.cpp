#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>

using std::unordered_map;
using std::vector;
constexpr int N = 100001;

template<typename T, typename U>
void dfs(int& id, T& graph, int cur, U& check){
	check[cur] = ++id;
	for(auto next: graph[cur]){
		if(check[next]) continue;
		dfs(id, graph, next, check);
	}
}

int main(){
	unordered_map<int, vector<int>> graph{};
	int check[N] = { 0, };
	
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	for(int i = 0; i < m; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(auto& [_, v]: graph)
		std::sort(v.begin(), v.end());
	
	int id = 0;
	dfs(id, graph, r, check);

	for(int i = 1; i <= n; i ++)
		printf("%d\n", check[i]);
	

	return 0;
}
