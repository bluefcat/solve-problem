#include <stdio.h>

#define MAXN 1000001

int main(){
	long long result = 0;
	long long n = 0;
	scanf("%lld", &n);
	
	long long min = 0;
	long long max = min + MAXN - 1;

	while(1){
		int map[MAXN] = { 0, };

		max = min + MAXN - 1;
		
		long long result = MAXN;
		long long x = 2;
		while(x * x <= max){
			long long square = x*x;
			long long idx = (long long)(min/square) + ((min%square == 0)?0:1);
			while(idx * square <= max){
				if(map[idx * square - min] == 1) goto NEXT;
				map[idx * square - min] = 1;
				result --;

				NEXT:
				idx ++;
			}
			x ++;
		}

		if(n <= result){
			long long pcnt = 0;
			long long idx = 0;	
			for(; idx < MAXN; idx ++){
				if(map[idx] == 0) pcnt ++;
				if(pcnt == n) break;
			}
			printf("%lld\n", min + idx);

			break;
		}
		
		n -= result;
		min += MAXN;
	}


	return 0;
}

