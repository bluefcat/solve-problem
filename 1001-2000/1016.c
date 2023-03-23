#include <stdio.h>

#define MAXN 1000001

int main(){
	int map[MAXN] = { 0, };

	long long min;
	long long max;
	scanf("%lld %lld", &min, &max);
	
	long long result = max - min + 1;
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

	printf("%lld\n", result);


	return 0;
}
