#include <cstdio>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

constexpr int N = 1001;
unordered_map<int, vector<int>> graph{};
unordered_map<int, int> p{}, q{};
bool visited[N] = { false, };

bool match(int u){
	visited[u] = true;
	for(auto& v: graph[u]){
		//not matched or match if other point move
		if(!q[v] || !visited[q[v]] && match(q[v])){
			p[u] = v;
			q[v] = u;
			return true;
		}
	}
	return false;
}

int main(){
	int n, m;
	n = 1000; m = 1000;
	//scanf("%d %d", &n, &m);
	for(int u = 1; u <= n; u ++){
		int s, v;
		s = 1000;
		//scanf("%d", &s);
		for(int j = 0; j < s; j ++){
			v = j+1;
			//scanf("%d", &v);
			graph[u].push_back(v);
		}
	}
	int result = 0;
	for(int i = 1; i <= n; i ++){
        if(result >= m) break;
		if(!p[i]){
			std::fill(visited, visited+N, false);
			if(match(i)) result++;
		}
	}
	
	printf("%d\n", result);
	return 0;
}
