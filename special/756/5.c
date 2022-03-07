#include <stdio.h>
#define ABS(X) (((X) > 0)? (X): -(X))
#define MIN(X, Y) (((X) > (Y))? (Y): (X))
long long cache[1000001];
long long remain[1000001];

int main(){
	long long n, k, sum = 0, result = 0;
	scanf("%lld %lld", &n, &k);

	for(long long i = 0; i < n; i ++){
		scanf("%lld", cache + i);
		sum += cache[i];
	}
	
	if(sum % k){
		printf("blobsad\n");
		return 0;
	}
	
	long long c = sum / k;

	for(long long i = 0; i < n; i ++){
		
		long long ltmp = cache[i] - (cache[i] / k) * k;
		long long rtmp = cache[i] - (cache[i] / k + 1) * k;

		if(ABS(ltmp) > ABS(rtmp)){
			remain[i] = rtmp;
		}
		else{
			remain[i] = ltmp;
		}
	}

	for(long long i = 0; i < n; i ++){
		printf("%lld\t", remain[i]);
		result += ABS(remain[i]);
	}
	printf("\n");

	printf("%lld\n", result >> 1);

	return 0;
}
