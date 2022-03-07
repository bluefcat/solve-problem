#include <stdio.h>
#define A 0
#define B 1

long long cache[2];

int main(){
	cache[A] = 1;

	int n = 0;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		long long atob = cache[A];
		long long btoa = cache[B];
		long long btob = cache[B];

		cache[A] = btoa;
		cache[B] = atob + btob;

	}

	printf("%lld %lld\n", cache[A], cache[B]);
	

	return 0;
}
