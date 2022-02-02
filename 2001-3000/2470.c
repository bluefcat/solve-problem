#include <stdio.h>
#include <stdlib.h>
#define ABS(X) (((X) > 0)? (X): -(X))
#define AMAX 2000000001

int compare(const void* x, const void* y){
	return *(int*)x - *(int*)y;	
}

int potion[100001];
int n;

int main(){
	int result[2] = { 0, };
	int density = AMAX;

	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", potion + i);

	qsort(potion, n, sizeof(int), compare);

	int start = 0, end = n-1;

	while(start < end){
		int tmp_density = potion[start] + potion[end];
		int diff_density = ABS(tmp_density);

		if(density > diff_density){
			density = diff_density;
			result[0] = potion[start];
			result[1] = potion[end];

			if(diff_density == 0) break;
		}

		if(tmp_density < 0){
			start ++;
		}
		else{
			end --;
		}
	}
	
	printf("%d %d\n", result[0], result[1]);

	return 0;
}
