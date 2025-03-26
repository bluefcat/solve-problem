#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>

using ll = long long;
using std::unordered_map;
using std::vector;

constexpr int N = 5001; //500001;

template<typename T>
void propagate(T& tree, ll account[], ll cache[], int idx){
	if(cache[idx] == 0) return;
	for(auto& nxt: tree[idx])
		cache[nxt] += cache[idx];
	
	account[idx] += cache[idx];
	cache[idx] = 0;
}

template<typename T>
void query(T& tree, ll account[], ll cache[], vector<int> route){
	for(auto& cur: route)
		propagate(tree, account, cache, cur);
}

template<typename T>
vector<int> get_route(T& rev, int s, int e){
	vector<int> result{};
	int cur = s;
	while(cur != e){
		result.push_back(cur);
		cur = rev[cur];
	}
	result.push_back(cur);
	return result;
} 


int main(){
	unordered_map<int, vector<int>> graph{};
	unordered_map<int, int> rev{};
	ll account[N] = { 0, };
	ll cache[N] = { 0, };

	int n, m;
	n = N-1; m = N-1;
	//scanf("%d %d", &n, &m);
	account[1] = 1;
	//scanf("%lld", account+1);
	for(int i = 2; i <= n; i ++){
		ll ac; int boss;
		ac = 1; boss = i-1;
		//scanf("%lld %d", &ac, &boss);
		account[i] = ac;
		graph[boss].push_back(i);
		rev[i] = boss;
	}
	
	bool flag = false;
	for(int i = 0; i < m; i ++){
		char oper;
		int x, y;
		oper = (i&1)?'u':'p';
		//scanf(" %c", &oper);
		switch(oper){
			case 'p':
				x = 1;
				y = 1;
				flag = true;
				//scanf("%d %d", &x, &y);
				for(auto& nxt: graph[x])
					cache[nxt] += y;
				break;
			case 'u':
				x = N-1;
				//scanf("%d", &x);
				if(flag){
					auto route = get_route(rev, x, 1);
					std::reverse(route.begin(), route.end());
					query(graph, account, cache, route);
					flag = false;
				}
				printf("%lld\n", account[x]);
				break;
		}
	}

	return 0;
}
