#include <stdio.h>
#include <stdlib.h>

#define AMAX 4001

int compare(const void* x, const void* y){
	return (int)(*(long long*)x - *(long long*)y);
}

long long A[AMAX];
long long B[AMAX];
long long C[AMAX];
long long D[AMAX];

long long AB[AMAX*AMAX];
long long CD[AMAX*AMAX];

long long n, result;

int main(){
	scanf("%lld", &n);

	for(int i = 0; i < n; i ++){
		scanf("%lld %lld %lld %lld", A+i, B+i, C+i, D+i);
	}

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			AB[i*n+j] = -(A[i] + B[j]);
			CD[i*n+j] = C[i] + D[j];
		}
	}
	
	qsort(CD, n*n, sizeof(long long), compare);

	
	long long start = 0, end = n*n;

	for(int i = 0; i < n*n; i ++){
		start = 0, end = n*n;

		while(start < end){
			long long mid = (start + end) / 2;
			if(AB[i] > CD[mid]) start = mid + 1;
			else end = mid;
		}

		long long lower = end;
		
		start = 0, end = n*n;

		while(start < end){
			long long mid = (start + end) / 2;

			if(AB[i] >= CD[mid]) start = mid + 1;
			else end = mid;
		}
		long long upper = end;

		result += upper - lower;
	}

	
	printf("%lld\n", result);


	return 0;
}
