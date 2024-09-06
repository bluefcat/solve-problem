#include <cstdio>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::pair;

constexpr int N = 2001;
int degree[N] = { 0, };
int life[N][N] = { 0, };
unordered_map<int, vector<pair<int, int>>> edges{};

template<typename U>
int dfs(int from, U& visited){
	int result = 1;
	visited[from] = true;
	for(auto& [_, to]: edges[from]){
		if(visited[to]) continue;
		result += dfs(to, visited);
	}
	return result;
}

void eulerian(int from){
	for(auto& [_, to]: edges[from]){
		if(life[from][to] <= 0) continue;
		
		life[from][to] --;
		life[to][from] --;
		eulerian(to);
	}

	printf("%d ", from);
}

int main(){
	
	int n = 0;
	scanf("%d", &n);
	
	for(int from = 1; from <= n; from ++){
		for(int to = 1; to <= n; to ++){
			int v = 0;
			scanf("%d", &v);
			if(from > to || v == 0) continue;
			edges[from].push_back({from, to});
			edges[to].push_back({to, from});
			life[from][to] += v;
			life[to][from] += v;

			degree[from] += v;
			degree[to] += v;
		}
	}

	for(int i = 1; i <= n; i ++){
		if(degree[i]&1){
			printf("-1\n");
			return 0;
		}
	}
	unordered_map<int, bool> visited{};
	int start = 1;
	bool flag = false;
	for(int i = 1; i <= n; i ++){
		if(visited[i]) continue;
		int size = dfs(i, visited);
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
	
	eulerian(start);
	printf("\n");

	return 0;
}
