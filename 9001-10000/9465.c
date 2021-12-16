#include <stdio.h>

#define MAXN 100001
#define MAX(X, Y) (((X) > (Y))? (X): (Y))


int main(){
	int T;
	scanf("%d", &T);

	for(int t = 0; t < T; t ++){
		int n;
		scanf("%d", &n);
		
		int sticker[2][MAXN];
		int zcache[MAXN] = { 0, };
		int ocache[MAXN] = { 0, };

		for(int i = 0; i < 2; i ++){
			for(int j = 1; j <= n; j ++) scanf("%d", sticker[i]+j);	
		}
		

		zcache[1] = sticker[0][1];
		ocache[1] = sticker[1][1];


		for(int i = 2; i <= n; i ++){
			zcache[i] = MAX(ocache[i-1], ocache[i-2]) + sticker[0][i];
			ocache[i] = MAX(zcache[i-1], zcache[i-2]) + sticker[1][i];
		}

		printf("%d\n", MAX(zcache[n], ocache[n]));

	}
	return 0;
}
