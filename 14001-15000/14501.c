#include <stdio.h>
#define MAX(X, Y) ((X) > (Y)? (X): (Y))

int cache[17];
int schedule[17][2];

int main(){
	int N, result = 0;
	
	scanf("%d", &N);
	for(int i = 1; i <= N; i ++){
		scanf("%d %d", schedule[i]+0, schedule[i]+1);
		cache[i] = schedule[i][1];
	}
	
	for(int i = 2; i <= N; i ++){
		for(int j = 1; j < i; j ++){
			if(i - j >= schedule[j][0])
				cache[i] = MAX(cache[i], (cache[j] + schedule[i][1]));
		}
	}
	
	for(int i = 0; i <= N; i ++){
		if(i + schedule[i][0] <= N+1) result = MAX(result, cache[i]);
	}

	printf("%d\n", result);

	return 0;
}
