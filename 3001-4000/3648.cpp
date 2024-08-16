#include <cstdio>
#include <unordered_map>
#include <vector>
#include <stack>

using std::vector;
using std::unordered_map;
using std::stack;

constexpr int N = 1001;

template<typename T, typename U>
int build(int& id, T& graph, T& scc, int cur, int* ids, bool* finished, U& s){
	ids[cur+N] = ++id;
	s.push(cur);
	int result = ids[cur+N];	
	for(auto& next: graph[cur]){
		if(ids[next+N] == 0)
			result = std::min(result, build(id, graph, scc, next, ids, finished, s));
		else if(!finished[next+N])
			result = std::min(result, ids[next+N]);
	}
	if(ids[cur+N] != result) return result;
	while(true){
		int x = s.top(); s.pop();
		scc[result].push_back(x);
		ids[x+N] = result;
		finished[x+N] = true;
		if(x == cur) break;
	}
	return result;
}

int main(){
	unordered_map<int, vector<int>> graph{};
	stack<int> s{};
	unordered_map<int, vector<int>> scc{};

	int n, m;

	while(scanf("%d %d", &n, &m) != EOF){
		int id = 0;
		int ids[2*N] = { 0, };
		bool finished[2*N] = { 0, };
		for(int i = 0; i < m; i ++){
			int u, v;
			scanf("%d %d", &u, &v);
			graph[-u].push_back(v);
			graph[-v].push_back(u);
		}
		graph[-1].push_back(1);
		for(int i = -n; i <= n; i++){
			if(i == 0) continue;
			if(finished[i+N]) continue;
			build(id, graph, scc, i, ids, finished, s);	
		}


		int result = 1;
		
		for(int i = 1; i <= n; i ++){
			if(ids[i+N] == ids[-i+N]){
				result = 0;
				break;
			}
		}
		printf("%s\n", result?"YES":"NO");
	}

	return 0;
}
