#include <cstdio>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::pair;

template<typename T, typename U>
int dfs(T& graph, int from, U& visited){
	int result = 1;
	visited[from] = true;
	for(auto& [_, to]: graph[from]){
		if(visited[to]) continue;
		result += dfs(graph, to, visited);
	}
	return result;
}

template<typename T, typename U>
void eulerian(T& edges, U& life, int from){
	for(auto& [_, to]: edges[from]){
		if(life[from][to] <= 0) continue;
		
		life[from][to] --;
		life[to][from] --;
		eulerian(edges, life, to);
	}

	printf("%d ", from);
}


int main(){
	unordered_map<int, int> degree{};
	unordered_map<int, vector<pair<int, int>>> edges{};
	unordered_map<int, unordered_map<int, int>> life{};
	
	int n = 0;
	scanf("%d", &n);
	for(int from = 1; from <= n; from ++){
		for(int to = 1; to <= n; to ++){
			int v = 0;
			scanf("%d", &v);
			if(from > to || v == 0) continue;
			edges[from].push_back({from, to});
			edges[to].push_back({to, from});
			life[from][to] ++;
			life[to][from] ++;

			degree[from] ++;
			degree[to] ++;
		}
	}

	for(int i = 1; i <= n; i ++){
		if(degree[i]&1){
			printf("-1\n");
			return 0;
		}
	}
	unordered_map<int, bool> visited{};
	int start;
	bool flag;
	for(int i = 1; i <= n; i ++){
		if(visited[i]) continue;
		int size = dfs(edges, i, visited);
		if(size > 1){
			if(flag){
				printf("-1\n");
				return 0;
			}
			else{
				start = i;
				flag = true;
			}
		}
	}
	
	eulerian(edges, life, 1);
	printf("\n");

	return 0;
}
