#include <cstdio>
#include <vector>
#include <algorithm>

constexpr int N = 21;

template<typename T>
bool all(int n, T& conditions){
	bool result = true;
	for(int i = 0; i < n; i ++) result &= (conditions[i] != 0);
	return result;
}


template<typename T, typename P, typename Q>
int solution(T& network, P& set, Q& cover, int n, int x){
	if(all(n, cover)) return x;
	
	int result = 21;

	for(int i = 0; i < n; i ++){
		if(set[i]) continue;
		
		set[i] = true;
		cover[i] ++;
		for(auto& f: network[i]) cover[f] ++;

		result = std::min(result, solution(network, set, cover, n, x+1));

		set[i] = false;
		cover[i] --;
		for(auto& f: network[i]) cover[f] --;
	}
	return result;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		int n;
		int result = 21;

		std::vector<int> network[N]{}; //[0, n)
		bool set[N] = { false, };
		int cover[N] = { 0, };

		scanf("%d", &n);
		for(int i = 0; i < n; i ++){
			int m;
			scanf("%d", &m);
			for(int j = 0; j < m; j ++){
				int tmp;
				scanf("%d", &tmp);
				network[i].emplace_back(tmp-1);
			}
		}

		printf("%d\n", solution(network, set, cover, n, 0));

	}
	return 0;
}
