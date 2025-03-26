#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

using std::vector;
using std::unordered_map;
using std::stack;
using std::queue;

constexpr int N = 100001;

template<typename T, typename U>
int build(
	int& id, int* scc, T& graph, U& s, int cur, int* ids, bool* finished
){
	ids[cur] = ++id;	
	s.push(cur);
	int result = ids[cur];

	for(int next: graph[cur]){
		if(ids[next] == 0){
			result = std::min(result, build(id, scc, graph, s, next, ids, finished));
		}
		else if(finished[next] == false){
			result = std::min(result, ids[next]);
		}
	}

	if(ids[cur] != result) return result;
	while(true){
		int x = s.top(); s.pop();
		finished[x] = true;
		scc[x] = cur;
		if(x == cur) break;
	}

	return result;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		
		unordered_map<int, vector<int>> graph{};
		unordered_map<
			int, unordered_map<int, bool>
		> conn{};
		int scc[N] = { 0, };
		int order[N] = { 0, }; // scc's order

		for(int i = 0; i < m; i ++){
			int u, v;
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
		}
		
		{
			int id = 0;
			int ids[N] = { 0, };
			stack<int> s{};
			bool finished[N] = { false, };
			for(int i = 1; i <= n; i ++){
				if(finished[i]) continue;
				build(id, scc, graph, s, i, ids, finished);
			}
		}
		
		{
			bool check[N] = { false, };
			queue<int> q{};
			for(int i = 1; i <= n; i ++){
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
		}
		
		bool scc_check[N] = { false, };
		int result = 0;
		for(int i = 1; i <= n; i ++) printf("(%d %d), ", i, scc[i]); printf("\n");
		for(int i = 1; i <= n; i ++){
			if(scc_check[scc[i]]) continue;
			scc_check[scc[i]] = true;
			printf("%d(%d), ", scc[i], order[scc[i]]);
			if(order[scc[i]] == 0) result ++;
		}
		printf("%d\n", result);
	}
	return 0;
}
