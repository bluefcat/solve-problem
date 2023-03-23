#include <cstdio>
#include <algorithm>
#include <map>
#include <stack>

int main(){
	int result = 0;
	int n;
	scanf("%d", &n);
	
	std::multimap<int, std::pair<int, int>> tre;
	std::map<int, bool> visited;
	std::stack<std::pair<int, int>> next_visited;

	for(int i = 0; i < n; i ++){
		int v;
		scanf("%d", &v);
		
		visited.insert({v, false});

		int x[2] = { 0, };
		int idx = 0;

		while(scanf("%d", x+idx) && x[idx] != -1){
			if(idx == 1){
				tre.insert({v, {x[0], x[1]}});
			}
			idx = (idx + 1) % 2;
		}
		
	}
	
	for(int i = 1; i <= n; i ++){
		next_visited.push({i, 0});
		
		while(!next_visited.empty()){
			auto p = next_visited.top(); next_visited.pop();
			int x = p.first;
			int s = p.second;
			result = std::max(s, result);
			visited[x] = true;


			auto range = tre.equal_range(x);
			for(auto& pair = range.first; pair != range.second; ++pair){
				int next = pair->second.first;
				int dist = pair->second.second;
				
				if(visited[next]) continue;

				next_visited.push({next, s+dist});
			}
		}
	}


	printf("%d\n", result);
	return 0;
}
