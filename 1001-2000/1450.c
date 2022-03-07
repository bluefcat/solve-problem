#include <stdio.h>

long long bag[31];

int main(){
	long long result = 0;
	long long n, c;
	scanf("%lld %lld", &n, &c);

	for(long long i = 0; i < n; i ++) scanf("%lld", bag+i);

	long long sum = bag[0];
	long long l = 0, r = 0;

	while(l <= r && r < n){

		if(sum < c){
			sum += bag[++r];
			result ++;
		}
		else if(sum == c){
			sum -= bag[++r];
			result ++;
		}
		else{
			sum -= bag[l++];
		}

	}


	printf("%lld\n", result);

	return 0;
}
