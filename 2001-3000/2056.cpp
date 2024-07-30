#include <cstdio>
#include <unordered_map>
#include <vector>
#include <queue>

constexpr int N = 10001;

using std::unordered_map;
using std::vector;
using std::priority_queue;

int main(){
	int result[N] = { 0, };
	int time[N] = { 0, };
	unordered_map<int, vector<int>> graph{};
	unordered_map<int, int> order{};

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		int c = 0;
		scanf("%d %d", time+i, &c);
		for(int j = 0; j < c; j ++){
			int y = 0;
			scanf("%d", &y);
			graph[y].push_back(i);
			order[i] ++;
		}

	}

	priority_queue<
		int,
		vector<int>,
		std::greater<int>
	> q{};
	for(int i = 1; i <= n; i ++){
		if(order[i] == 0){
			q.push(i);
			result[i] = time[i];
		}
	}

	for(int i = 0; i < n; i ++){
		int x = q.top(); q.pop();
		for(auto y: graph[x]){
			order[y] --;
			result[y] = std::max(result[y], result[x] + time[y]);
			if(order[y] == 0) q.push(y);
		}
	}
	
	int r = 0;
	for(int i = 1; i <= n; i ++) r = std::max(r, result[i]);
	printf("%d\n", r);
	return 0;
}
