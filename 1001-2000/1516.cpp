#include <cstdio>
#include <vector>
#include <unordered_map> 
#include <queue>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::priority_queue;

constexpr int N = 501;

int main(){
	int result[N] = { 0, };
	int time[N] = { 0, };
	unordered_map<int, vector<int>> graph{};
	unordered_map<int, int> order{};

	int n = 0;
	scanf("%d", &n);

	for(int i = 1; i <= n; i ++){
		scanf("%d", time+i);
		int t = 0;
		while(scanf("%d", &t) && t != -1){
			graph[t].push_back(i);
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


	for(int i = 1; i <= n; i ++)
		printf("%d\n", result[i]);

	return 0;
}

