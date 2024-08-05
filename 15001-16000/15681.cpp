#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>

using std::unordered_map;
using std::vector;

constexpr int N = 10001;

template<typename T, typename U>
int build_depth(T& graph, U& depth, int* table, int root, int idx, int d){
	int result = d;
	for(int x: graph[idx]){
		if(x == root || table[x] != 0) continue;
		table[x] = idx;
		depth[d+1].push_back(x);
		result = std::max(
			result, 
			build_depth(graph, depth, table, root, x, d+1)
		);
	}
	return result;
}
int main(){
	unordered_map<int, vector<int>> graph{};
	unordered_map<int, vector<int>> depth{};
	int table[N] = { 0, };
	int result[N] = { 0, };
	int n, r, q;
	scanf("%d %d %d", &n, &r, &q);
	for(int i = 0; i < n-1; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	depth[0].push_back(r);	
	int d = build_depth(graph, depth, table, r, r, 0)+1;
	for(int i = d-1; i >= 0; i --){
		for(auto x: depth[i]){
			result[table[x]] += result[x] + 1;
		}
	}

	for(int i = 0; i < q; i ++){
		int u;
		scanf("%d", &u);
		printf("%d\n", result[u]+1);
	}

	return 0;
}
