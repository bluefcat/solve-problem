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

int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		int n;

		std::vector<int> network[N]{}; //[0, n)

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

		int result = 0xFFFF;
		for(int i = 0; i < (1 << (n+1)); i ++){
			bool set[N] = { false, };
			int tmp = 0;
			for(int b = 0; b < n; b ++){
				if(!((1 << b) & i)) continue;

				set[b] = true;
				for(auto& f: network[b]){
					set[f] = true;
				}
				tmp ++;

			}
			if(all(n, set)) result = std::min(result, tmp);
		}
		printf("%d\n", result);
	}
	return 0;
}
