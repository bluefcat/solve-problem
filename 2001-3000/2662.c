#include <stdio.h>
#define MAXINV 301
#define MAXCOM 21

unsigned int cache[MAXINV][MAXCOM];
int com[MAXCOM][MAXINV];
int inv[MAXCOM];

int main(){
	int N, M;
	
	scanf("%d %d", &N, &M);
	
	for(int i = 1; i <= N; i ++){
		int x = 0;
		scanf("%d", &x);
		for(int j = 1; j <= M; j ++){
			scanf("%d", com[j] + x);
		}
	}

	return 0;
}
