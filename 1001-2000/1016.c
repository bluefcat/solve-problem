#include <stdio.h>


int main(){
	long long min, max;

	scanf("%lld %lld", &min, &max);

	for(long long idx = min; idx*idx < max; idx ++){
		long long sidx = idx * idx;
		
		printf("%lld\n", sidx);

	}

	return 0;
};
