#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::stack;
using std::queue;

constexpr int N = 10001;

template<typename T, typename U, typename V>
int build(int& id, T& graph, int cur, int* ids, bool* finished, U& s, V& result){
	ids[cur] = ++id;
	s.push(cur);
	int parent = ids[cur];

	for(int nxt: graph[cur]){
		if(ids[nxt] == 0)
			parent = std::min(
				parent,
				build(id, graph, nxt, ids, finished, s, result)
			);
		else if(finished[nxt] == 0)
			parent = std::min(parent, ids[nxt]);
	}

	if(parent != ids[cur]) return parent;
	
	vector<int> tmp{};
	while(true){
		int x = s.top(); s.pop();
		tmp.push_back(x);
		ids[x] = parent;
		finished[x] = true;
		if(x == cur) break;
	}
	std::sort(tmp.begin(), tmp.end());
	result.push_back(tmp);

	return parent;
}

int main(){
	int id = 0;
	unordered_map<int, unordered_set<int>> graph{};
	int ids[N] = { 0, };
	bool finished[N] = { false, };
	stack<int> st{};
	vector<vector<int>> scc{};

	int n, m, s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);

	for(int i = 0; i < m; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].insert(v);
	}
	
	build(id, graph, s, ids, finished, st, scc);
	std::reverse(scc.begin(), scc.end());


	unordered_map<int, unordered_set<int>> scc_graph{};
	bool scc_check[N] = { false, };
	int scc_cache[N] = { false, };
	int scc_result[N] = { false, };
	int answer = 0;
	bool visitable = false;

	queue<int> q{};
	q.push(s);
	scc_check[s] = true;
	
	while(!q.empty()){
		int cur = q.front(); q.pop();
		visitable |= (cur == t);
		for(int nxt: graph[cur]){
			if(ids[nxt] != ids[cur])
				scc_graph[ids[cur]].insert(ids[nxt]);

			if(scc_check[nxt]) continue;
			q.push(nxt);
			scc_check[nxt] = true;
		}
	}

	for(auto& v: scc)
		for(auto& x: v) scc_cache[ids[x]] += 1;
	
	scc_result[ids[s]] = scc_cache[ids[s]];
	for(auto& u: scc){
		int key = ids[u[0]];
		for(auto& v: scc_graph[key])
			scc_result[v] = std::max(scc_cache[v]+scc_result[key], scc_result[v]);
	}

	if(visitable == false){
		printf("0\n");
		return 0;
	}
	printf("%d\n", scc_result[ids[t]]);
	return 0;
}


