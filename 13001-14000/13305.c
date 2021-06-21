#include <stdio.h>
#include <limits.h>

int road[100001][2];

int main(){
	long long result = 0;
	int n;

	scanf("%d", &n);
	for(int i = 0; i < n-1; i ++){
		scanf("%d", road[i]+0);
	}

	scanf("%d", road[0]+1);
	for(int i = 1; i < n; i ++){
		scanf("%d", road[i]+1);
		if(road[i-1][1] < road[i][1]) road[i][1] = road[i-1][1];
	}

	for(int i = 0; i < n-1; i ++){
		result += road[i][0]*road[i][1];
	}

	printf("%lld\n", result);
	return 0;
}
