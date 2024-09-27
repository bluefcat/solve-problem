#include <cstdio>
#include <algorithm>

using std::min;

constexpr int N = 20;
int cache[N+1][1<<N];

int main(){
	int field[N+1][N] = { 0, };
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < n; j ++)
			scanf("%d", field[i]+j);
	}
	
	//employee
	for(int i = 1; i <= n; i ++){
		for(int j = 0; j < (1 << N); j ++){
			//task
			for(int t = 0; t < n; t ++){
				if(!((j & (1 << t)) == (1 << t))) continue;
				if(cache[i][j ^ (1 << t)] == 0){
					cache[i][j ^ (1 << t)] = cache[i-1][j] + field[i][t];
				}
				cache[i][j ^ (1 << t)] = min(
					cache[i][j ^ (1 << t)], 
					cache[i-1][j] + field[i][t]
				);
			}
		}
	}

	int result = cache[n][0];

	//for(int i = 2; i <= n; i ++)
	//	result = min(result, cache[i][(1<<n)-1]);

	printf("%d\n", result);

	return 0;
}
