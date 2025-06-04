#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

using lint = long long;
constexpr int P = 10001;
bool is_prime[P] = { false, };

std::unordered_map<lint, std::vector<lint>> graph{};
std::vector<lint> prime;

void build_sieve(){
	for(int i = 2; i < P; i ++) is_prime[i] = true;	
	for(int p = 2; p < P; p ++){
		if(is_prime[p])
			prime.emplace_back(p);
		
		for(auto& q: prime){
			if(p*q >= P) break;
			is_prime[p*q] = false;
			if(p%q == 0) break;
		}
	}
}

lint change(int x, int d, int p){ // len(x) = 4
	lint result = 0;	
	lint tmp[4] = { 
		(x/1000) % 10,
		(x/100) % 10,
		(x/10) % 10, 
		x % 10
	};
	tmp[3-d] = p;
	return tmp[0]*1000+tmp[1]*100+tmp[2]*10+tmp[3];
}

int main(){
	build_sieve();
	for(int i = 1000; i < 10'000; i ++){
		if(!is_prime[i]) continue;

		for(int d = 0; d < 4; d ++){
			for(int p = 0; p < 10; p ++){
				lint j = change(i, d, p);
				if(!is_prime[j]) continue;
				graph[i].emplace_back(j);
				graph[j].emplace_back(i);
			}
		}
	}
	
	int t;
	scanf("%d", &t);
	while(t--){
		lint x, y, r = -1, rc;
		scanf("%lld %lld", &x, &y);
		if(x == y){
			printf("0\n");
			continue;
		}
		
		bool visited[P] = { false, };
		std::queue<std::pair<lint, lint>> q{};
		
		q.push({x, 0});
		visited[x] = true;
		
		while(!q.empty()){
			auto [c, cnt] = q.front(); q.pop();
			for(auto& n: graph[c]){
				if(visited[n]) continue;
				q.push({n, cnt+1});
				visited[n] = true;

				if(n == y){
					r = n;
					rc = cnt+1;
					goto NEXT;
				}
			}
		}
		NEXT:
		if(r == -1){
			printf("Impossible\n");
			continue;
		}
		printf("%lld\n", rc);

	}
	return 0;
}
