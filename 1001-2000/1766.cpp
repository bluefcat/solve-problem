#include <cstdio>
#include <unordered_map>
#include <queue>
#include <vector>

using std::unordered_map;
using std::priority_queue;
using std::vector;

int main(){
	int n, m;
	vector<int> order{};
	unordered_map<
		int,
		vector<int>
	> graph{};

	scanf("%d %d", &n, &m);
	for(int i = 0; i <= n; i ++)
		order.push_back(0);

	for(int i = 0; i < m; i ++){
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x].push_back(y);
		order[y] ++;
	}


	priority_queue<
		int, 
		vector<int>, 
		std::greater<int>
	> q{};	
	vector<int> result{};
	for(int i = 1; i <= n; i ++)
		if(order[i] == 0) q.push(i);
	
	for(int i = 0; i < n; i ++){
		if(q.empty()) break;
		
		int cur = q.top(); q.pop();
		result.push_back(cur);
		
		for(auto y: graph[cur])
			if(--order[y] == 0) q.push(y);
	}
	
	for(auto x: result)
		printf("%d ", x);
	printf("\n");

	return 0;
}
