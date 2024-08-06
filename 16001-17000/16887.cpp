#include <cstdio>

using ll = long long;
constexpr int N = 3000001; 
constexpr int M = 34; 

int g[N] = { 0, 1, 2, 3 };
int f[M] = { 0, 1 };
int main(){
	for(int i = 2; i < M; i ++)
		f[i] = f[i-1] + f[i-2];

	for(int i = 4; i < N; i ++){
		bool flag[M] = { 0, };
		for(int j = 1; f[j] <= i; j ++){
			flag[g[i-f[j]]] = true;
		}
		
		for(int v = 0; v < M; v ++)
			if(!flag[v]){
				g[i] = v;
				break;
			}
	}
	int n, result = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int x = 0;
		scanf("%d", &x);
		result ^= g[x];
	}
	
	if(result){
		printf("koosaga\n");
		return 0;
	}
	printf("cubelover\n");
	return 0;
}
