#include <stdio.h>
#include <stdlib.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
long long tree[1000001];

int main(){
	long long n, m, max = 0;
	scanf("%lld %lld", &n, &m);

	for(int i = 0; i < n; i ++){
		scanf("%lld", tree+i);
		max = MAX(max, tree[i]);
	}

	long long start = 0;
	long long end = max;
	
	long long result = 0;

	while(start <= end){
		long long mid = (end + start) >> 1;

		long long total = 0;
		for(int i = 0; i < n; i ++) total += MAX(tree[i]-mid, 0);
		
		if(total >= m){
			result = MAX(result, mid);
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}

	}

	printf("%lld\n", result);

	return 0;
}
