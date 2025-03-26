#include <cstdio>
#include <unordered_map>
#include <unordered_set>

using std::unordered_map;
using std::unordered_set;

constexpr int N = 251;

unordered_map<int, unordered_set<int>> graph{};
unordered_map<int, int> a{}, b{};

bool visited[N] = { 0, };

bool match(int n, int cur){
	visited[cur] = true;
	
	for(auto next: graph[cur]){
		if(b[next] == 0 || !visited[b[next]] && match(n, b[next])){
			a[cur] = next;
			b[next] = cur;
			return true;
		}
	}
	return false;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			char k;
			scanf(" %c", &k);
			if(k == '*'){ 
				graph[2*i-1].insert(2*j);
				graph[2*j].insert(2*i-1);
			}
		}
	}

	for(auto [k, _]: graph){
		for(int x = 1; x <= 2*n; x ++) visited[x] = false;
		match(n, k);	
	}
	
	int result = 0;
	for(int i = 1; i <= 2*n; i ++){
		printf("%d=%d\n", i, a[i]);
		result += (a[i] != 0);
	}
	printf("%d\n", result);

	return 0;
}
