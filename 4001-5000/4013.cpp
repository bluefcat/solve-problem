#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <queue>

using std::vector;
using std::unordered_map;
using std::stack;
using std::queue;
using std::priority_queue;

constexpr int N = 500001;

template<typename T, typename S, typename R>
int build(int& id, T& graph, int cur, int* ids, bool* finished, S& s, R& result){
	ids[cur] = ++id;
	s.push(cur);
	int r = ids[cur];
	for(auto& nxt: graph[cur]){
		if(ids[nxt] == 0)
			r = std::min(
					r, 
					build(id, graph, nxt, ids, finished, s, result)
			);
		else if(!finished[nxt])
			r = std::min(r, ids[nxt]);
	}

	if(r != ids[cur]){
		ids[cur] = r;
		return r;
	}
	vector<int> tmp{};
	while(true){
		int x = s.top(); s.pop();
		tmp.push_back(x);
		ids[x] = r;
		finished[x] = true;
		if(x == cur) break;
	}
	std::sort(tmp.begin(), tmp.end());
	result.push_back(tmp);
	return r;
}

int main(){
	int id;
	unordered_map<int, vector<int>> graph{};
	vector<vector<int>> result{};
	stack<int> s{};
	int ids[N] = { 0, };
	int cache[N] = { 0, };
	bool finished[N] = { false, };
	bool end[N] = { false, };
	int n, m, start, p;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
	}
	for(int i = 0; i < n; i ++)
		scanf("%d", cache+i+1);
	
	scanf("%d %d", &start, &p);
	for(int i = 0; i < p; i ++){
		int u;
		scanf("%d", &u);
		end[u] = true;
	}
	
	build(id, graph, start, ids, finished, s, result);
	std::reverse(result.begin(), result.end());
	
	unordered_map<int, unordered_map<int, bool>> scc_graph{};
	bool scc_check[N] = { false, };
	int scc_cache[N] = { 0, };
	int scc_result[N] = { 0, };
	int answer = 0;

	queue<int> q{};
	
	q.push(start);
	scc_check[start] = true;
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(auto& nxt: graph[cur]){
			if(ids[nxt] != ids[cur]){
				scc_graph[ids[cur]][ids[nxt]] = true;
			}
			if(scc_check[nxt]) continue;
			q.push(nxt);
			scc_check[nxt] = true;
		}
	}

	for(auto& v: result){
		int k;
		for(auto& x: v){
			k = ids[x];
			scc_cache[ids[x]] += cache[x];
		}
	}
	
	scc_result[ids[start]] = scc_cache[ids[start]];

	for(auto& u: result){
		int k = ids[u[0]];

		for(auto& [v, _]: scc_graph[k]){
			scc_result[v] = std::max(scc_result[v], scc_cache[v] + scc_result[k]);
		}
	}

	for(int i = 1; i <= n; i ++){
		if(end[i]) answer =std::max(answer, scc_result[ids[i]]);
	}

	printf("%d\n", answer);
	return 0;
}



