#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;

constexpr int N = 300001;

template<typename T, typename U>
int find(T& graph, U& index, int cur, int* answer){
	if(answer[cur] != 0) return answer[cur];

	int count = 0;
	vector<int> visited{cur};
	
	while(index[cur].size() != 0){
		auto iter = std::lower_bound(
				index[cur].begin(), 
				index[cur].end(),
				count
		);
		if(iter == index[cur].end()) break;
		int idx = iter - index[cur].begin();
		count = index[cur][idx];	
		cur = graph[count];
		visited.push_back(cur);
	}
	for(int i = 0; i < visited.size()-1; i ++){
		answer[visited[i]] = cur;
	}
	return cur;
}

int main(){
	vector<int> graph{}; graph.push_back(0);
	unordered_map<int, vector<int>> index{};
	int n, m;

	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i ++){
		int u, v;
		scanf("%d %d", &u, &v);
		index[u].push_back(i+1);
		graph.push_back(v);
	}
	int answer[N] = { 0, };
	for(int i = 1; i <= n; i ++){
		int x = find(graph, index, i, answer);
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}
