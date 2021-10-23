#include <stdio.h>

#define MAXN 100001
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int zcache[MAXN];
int ocache[MAXN];
int cache[MAXN];
int sticker[2][MAXN];

int main(){
	int T;
	scanf("%d", &T);

	for(int t = 0; t < T; t ++){
		int n;
		scanf("%d", &n);

		for(int i = 0; i < 2; i ++){
			for(int j = 0; j < n; j ++) scanf("%d", sticker[i]+j);	
		}
		
		zcache[0] = sticker[0][0];
		ocache[0] = sticker[1][0];

		for(int i = 1; i < n; i ++){
			zcache[i] = zcache[i-1] + sticker[i%2][i];
			ocache[i] = ocache[i-1] + sticker[(i+1)%2][i];
		}

		cache[0] = MAX(sticker[0][0], sticker[1][0]);
		cache[1] = MAX((sticker[0][0] + sticker[1][1]), (sticker[1][0] + sticker[0][1]));
		
		for(int i = 2; i < n; i ++){
			cache[i] = MAX((cache[i-2] + sticker[0][i]), (cache[i-2] + sticker[1][i]));
			
			int tmp = MAX(zcache[i], ocache[i]);
			cache[i] = MAX(cache[i], tmp);
		}
		
		printf("%d\n", cache[n-1]);
	}
	return 0;
}
