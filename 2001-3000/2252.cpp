#include <cstdio>
#include <unordered_map>
#include <vector>
#include <queue>

using std::unordered_map;
using std::vector;
using std::queue;

int main(){
	unordered_map<
		int,
		vector<int>
	> graph{};
	vector<int> order{};

	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i <= n; i ++)
		order.push_back(0);
	
	for(int i = 0; i < m; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		order[y] ++;
	}
	
	queue<int> q{};	
	vector<int> result{};
	for(int i = 1; i <= n; i ++){
		if(order[i] == 0) q.push(i);
	}
	
	for(int i = 0; i < n; i ++){
		if(q.empty()) break;
		
		int cur = q.front(); q.pop();
		result.push_back(cur);
		for(auto x: graph[cur]){
			if(--order[x] == 0)	q.push(x);
		}
	}
	
	for(auto x: result){
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}
