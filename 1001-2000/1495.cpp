#include <cstdio>

constexpr int N = 51;
constexpr int M = 1001;

bool cache[N][M];

int main(){
	int n, s, m;
	scanf("%d %d %d", &n, &s, &m);

	cache[0][s] = true;
	
	
	for(int i = 1; i <= n; i ++){
		int v;
		scanf("%d", &v);

		for(int p = 0; p < M; p ++){
			if(cache[i-1][p] == false) continue;
			if(p + v <= m){
				cache[i][p+v] = true;
			}
			if(p - v >= 0){
				cache[i][p-v] = true;
			}
		}
	}
	for(int i = m; i >= 0; i --){ 
		if(cache[n][i]){
			printf("%d\n", i);
			return 0;
		}
	}
	
	printf("-1\n");

	return 0;
}
