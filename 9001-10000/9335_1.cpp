#include <cstdio>
#include <vector>
#include <algorithm>

constexpr int N = 21;

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
				network[i].emplace_back(i);
				network[i].emplace_back(tmp-1);
			}
		}

		int result = 0xFFFF;
		for(int i = 0; i < (1 << (n+1)); i ++){
			int set = 0, tmp = 0;
			for(int b = 0; b < n; b ++){
				if(!((1 << b) & i)) continue;
				for(auto& f: network[b]) set |= (1 << f);
				tmp ++;

			}
			if(set == (1 << n) - 1) 
				result = std::min(result, tmp);
		}
		printf("%d\n", result);
	}
	return 0;
}
