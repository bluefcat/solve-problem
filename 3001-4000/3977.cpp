#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>

using std::vector;
using std::unordered_map;
using std::queue;
using std::stack;

constexpr int N = 200001;

template<typename R, typename T, typename U>
int SCC(R& outcome, int& id, T& graph, int cur, int* parent, bool* finished, U& s){
	parent[cur] = ++id;
	s.push(cur);
	int result = parent[cur];

	for(int next: graph[cur]){
		if(parent[next] == 0)
			result = std::min(result, SCC(outcome, id, graph, next, parent, finished, s));
		else if(!finished[next])
			result = std::min(result, parent[next]);
	}
	if(result != parent[cur]) return result;
	
	while(true){
		int x = s.top(); s.pop();
		finished[x] = true;
		outcome[x] = result;	
		if(x == cur) break;
	}

	return result;
}

template<typename T>
void build(int* result, int& id, T& graph, int cur, bool* finished){
	int parent[N] = { 0, };
	stack<int> s{};

	SCC(result, id, graph, cur, parent, finished, s);
}

int main(){
	int t = 0;
	scanf("%d", &t);
	while(t--){
		unordered_map<int, vector<int>> graph{};	
		int id = 0;
		int scc[N] = { 0, };
		bool finished[N] = { false, };	
		int n, m;
		scanf("%d %d", &n, &m);

		for(int i = 0; i < m; i ++){
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
		}
		
		for(int i = 0; i < n; i ++){
			if(finished[i]) continue;
			build(scc, id, graph, i, finished);
		}
		
		bool check[N] = { false, };
		int order[N] = { 0, };
		unordered_map<int, unordered_map<int, bool>> conn{};
		queue<int> q{};
		for(int i = 0; i < n; i ++){
			if(check[i]) continue;
			q.push(i);
			check[i] = true;
			while(!q.empty()){
				int cur = q.front(); q.pop();
				for(int next: graph[cur]){
					if(scc[cur] != scc[next]){
						order[scc[next]] += !conn[scc[cur]][scc[next]];
						conn[scc[cur]][scc[next]] = true;
					}

					if(check[next]) continue;
					q.push(next);
					check[next] = true;
				}
			}
		}
		
		int result = 0;
		bool scc_check[N] = { false, };
		for(int i = 0; i < n; i ++){
			if(scc_check[scc[i]]) continue;
			result += (order[scc[i]] == 0);
			scc_check[scc[i]] = true;
		}
		
		if(result != 1){
			printf("Confused\n");
		}
		else{	
			for(int i = 0; i < n; i ++){
				if(order[scc[i]] == 0) printf("%d\n", i);
			}
		}
		printf("\n");

	}
	return 0;
}

