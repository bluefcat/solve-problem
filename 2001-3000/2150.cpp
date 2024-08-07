#include <cstdio>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::stack;
using std::unordered_map;

constexpr int N = 10001;

template<typename T, typename U>
int build(
	int& count,
	T& sccs,
	int& id, 
	U& graph,
	int cur,
	int* parent,
	bool* finished,
	stack<int>& cand
){
	parent[cur] = ++id;
	cand.push(cur);

	int result = parent[cur];
	for(int next: graph[cur]){
		if(parent[next] == 0){
			result = std::min(
				result,
				build(count, sccs, id, graph, next, parent, finished, cand)
			);
		}
		else if(!finished[next]){
			result = std::min(result, parent[next]);
		}
	}

	if(parent[cur] != result) 
		return result;
	
	vector<int> scc{};

	while(true){
		int x = cand.top(); cand.pop();
		finished[x] = true;
		scc.push_back(x);
		if(x == cur) break;
	}
	count ++;
	std::sort(scc.begin(), scc.end());
	sccs.push_back(scc);

	return result;
}


int main(){
	int count = 0;
	vector<vector<int>> result{};

	unordered_map<int, vector<int>> graph{};
	stack<int> cand{};
	int parent[N] = { 0, };
	bool finished[N] = { false, };
	int n, m, id = 0;
	
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
	}

	build(count, result, id, graph, 1, parent, finished, cand);
	std::sort(
		result.begin(), 
		result.end(), 
		[](auto x, auto y){ return x[0] < y[0]; }
	);
	printf("%d\n", count);
	for(auto& v: result){
		for(int& node: v){
			printf("%d ", node);
		}
		printf("-1 \n");
	}

	return 0;
}
