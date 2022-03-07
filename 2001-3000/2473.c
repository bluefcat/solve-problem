#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ABS(X) (((X) > 0)? (X): -(X))

long long cache[5001];
long long answer[3];
long long sum = LLONG_MAX;

int compare(const void* x, const void* y){
	return *(long long*)x - *(long long*)y;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%lld", cache+i);

	qsort(cache, n, sizeof(long long), compare);
	
	for(int i = 0; i < n; i ++){
		int j = i+1;
		int k = n-1;

		while(j < k){
			long long s = cache[i] + cache[j] + cache[k];

			if(ABS(s) < sum){
				sum = ABS(s);
				answer[0] = cache[i]; answer[1] = cache[j]; answer[2] = cache[k];
			}
			
			if(s < 0) j ++;
			else k --;
		}
	}

	

	for(int i = 0; i < 2; i ++) printf("%lld ", answer[i]);
	printf("%lld\n", answer[2]);

	return 0;
}
