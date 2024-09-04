#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <array>

using std::unordered_map;
using std::unordered_set;
using std::array;

constexpr int N = 2001;

template<typename T, typename U, typename V>
bool match(T& graph, U& a, U& b, int cur, V& check){
	check[cur] = true;
	
	for(int next: graph[cur]){
		if(!b[next] || !check[b[next]] && match(graph, a, b, b[next], check)){
			a[cur] = next;
			b[next] = cur;
			return true;
		}
	}

	return false;
}

int main(){
	int n, m;
	unordered_map<int, unordered_set<int>> graph{};
	array<int, N> a{};
	array<int, N> b{};
	scanf("%d %d", &n, &m);
	
	for(int i = 1; i < 2*n+1; i +=2){
		// employee no.1 represent index 1 and 2;
		int s, x;
		scanf("%d", &s);
		for(int j = 0; j < s; j ++){
			scanf("%d", &x);
			graph[i+0].insert(x);
			graph[i+1].insert(x);
		}
	}
	int result = 0;
	array<bool, N> check{};
	for(int i = 1; i < 2*n+1; i ++){
		if(result == m) break;
		std::fill(check.begin(), check.end(), false);
		result += match(graph, a, b, i, check);
	}

	printf("%d\n", result);
	return 0;
}
