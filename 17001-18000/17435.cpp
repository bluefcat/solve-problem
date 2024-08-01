#include <cstdio>

constexpr int SN = 19;
constexpr int N = 20001; //200001;

int main(){
	int cache[SN][N] = { 0, };
	int n = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d", cache[0]+i);
	}

	for(int i = 1; i < SN; i ++)
		for(int j = 1; j <= n; j ++)
			cache[i][j] = cache[i-1][cache[i-1][j]];

	int q = 0;
	scanf("%d", &q);
	for(int i = 0; i < q; i ++){
		int t, x;
		scanf("%d %d", &t, &x);
		
		for(int f = SN-1; f >= 0; f --){
			if((t & (1<<f)) == (1<<f)){
				x = cache[f][x];	
			}
		}
		printf("%d\n", x);
	}
	return 0;
}
