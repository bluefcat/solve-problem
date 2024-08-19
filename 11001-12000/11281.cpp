#include <cstdio>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>

using std::unordered_map;
using std::vector;
using std::stack;

constexpr int N = 10001;

template<typename T, typename STACK, typename R>
int build(int& id, T& graph, int cur, int* scc, bool* finished, STACK& s, R& outcome){
	scc[cur+N] = ++id;
	s.push(cur);
	int result = scc[cur+N];

	for(auto& nxt: graph[cur]){
		if(scc[nxt+N] == 0)
			result = std::min(result, build(id, graph, nxt, scc, finished, s, outcome));
		else if(finished[nxt+N] == false)
			result = std::min(result, scc[nxt+N]);
	}
	
	if(result != scc[cur+N]){
		return result;
	} 
	
	vector<int> r{};
	while(true){
		int x = s.top(); s.pop();
		r.push_back(x);
		scc[x+N] = result;
		finished[x+N] = true;
		if(x == cur) break;
	}
	std::sort(r.begin(), r.end());
	outcome.push_back(r);

	return result;
}

int main(){
	unordered_map<int, vector<int>> graph{};
	vector<vector<int>> outcome{};
	int id = 0 ;
	int scc[2*N] = { 0, };
	bool finished[2*N] = { false, };
	stack<int> s {};
	int n, m;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < m; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[-u].push_back(v);
		graph[-v].push_back(u);
	}
	for(int i = -n; i <= n; i ++){
		if(finished[i+N] || i == 0) continue;
		build(id, graph, i, scc, finished, s, outcome);
	}
	std::reverse(outcome.begin(), outcome.end());
	
	int flag = 1;
	int result[2*N] = { 0, };
	for(int i = 0; i < 2*N; i ++) result[i] = -1;
	
	for(auto& v: outcome){
		if(flag == 0) break;
		bool visited[2*N] = { false, };
		for(auto& x: v){
			if(visited[-x+N]){
				flag = 0;
				break;
			}
			visited[x+N] = true;
			int k = std::abs(x)+N;
			if(result[k] != -1) continue;
			result[k] = (x<0);
		}
	}

	printf("%d\n", flag);
	if(flag == 0) return 0;
	for(int i = 1; i <= n; i ++){
		printf("%d ", result[i+N]);
	}
	printf("\n");

	return 0;
}
