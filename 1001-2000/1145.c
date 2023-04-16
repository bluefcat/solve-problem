#include <stdio.h>

long long main(){
	long long n[5] = { 0, };
	for(long long i = 0; i < 5; i ++) scanf("%lld", n+i);
	
	long long product = 1;
	for(long long i = 0; i < 5; i ++) product *= n[i];
	for(long long i = 1; i <= product; i ++){

		long long t = 0;
		for(long long c = 0; c < 5; c ++) if(i % n[c] == 0) t ++;

		if(t >= 3){
			printf("%lld\n", i);
			return 0;
		}
	}

	return 0;
}
