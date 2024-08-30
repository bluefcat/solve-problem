#include <cstdio>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

constexpr int N = 2001;

template<typename G, typename T, typename U>
bool match(
	G& graph, 
	T& p,
	T& q,
	int u, 
	U& visited
){
	visited[u] = true;
	for(auto& v: graph[u]){
		//not matched or match if other point move
		if(!q[v] || !visited[q[v]] && match(graph, p, q, q[v], visited)){
			p[u] = v;
			q[v] = u;
			return true;
		}
	}
	return false;
}

int main(){
	unordered_map<int, vector<int>> graph{};
	unordered_map<int, int> p{}, q{};
	bool visited[N] = { false, };
	int n, m;
	scanf("%d %d", &n, &m);

	for(int u = 1; u <= n; u ++){
		int s, v;
		scanf("%d", &s);
		for(int j = 0; j < s; j ++){
			scanf("%d", &v);
			graph[u].push_back(v);
		}
	}
	int result = 0;
	for(int i = 1; i <= n; i ++){
		if(!p[i]){
			std::fill(visited, visited+N, false);
			result += match(graph, p, q, i, visited);
		}
	}
	
	printf("%d\n", result);
	return 0;
}
