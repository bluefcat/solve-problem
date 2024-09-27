#include <cstdio>
#include <algorithm>
#include <unordered_map>

using std::min;
using std::unordered_map;

constexpr int N = 20;
unordered_map<int, int> cache[N+1]{};

int main(){
	int field[N+1][N] = { 0, };
	int n;
	scanf("%d", &n);
	cache[0][0] = 0;
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < n; j ++){
			scanf("%d", field[i]+j);
		}
	}
	
	//employee
	for(int i = 1; i <= n; i ++){
		for(auto [flag, prev]: cache[i-1]){
			for(int t = 0; t < n; t ++){
				int task = (1 << t);
				if((flag & task) == task) continue;
				if(cache[i][flag | task] == 0)
					cache[i][flag | task] = prev + field[i][t];
				cache[i][flag | task] = min(
					cache[i][flag | task],
					prev + field[i][t]
				);
			}

		}
	}

	int result = 0;
	for(auto [flag, prev]: cache[n]){
		result = prev;
	}

	printf("%d\n", result);

	return 0;
}
