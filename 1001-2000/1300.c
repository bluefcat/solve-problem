#include <stdio.h>

static inline int mn(int x, int y){
	return (((x) > (y))? (y): (x));
}


int main(){
	int n, k;
	scanf("%d\n%d", &n, &k);
	
	int result = 1;
	int start = 1, end = k;

	while(start <= end){
		int mid = (start + end) >> 1;

		int count = 0;
		for(int i = 1; i <= n; i ++){
			count += mn(mid / i, n);
		}

		if(count < k){
			start = mid + 1;
		}
		else{
			result = mid;
			end = mid - 1;
		}
	}

	printf("%d\n", result);


	return 0;
}
