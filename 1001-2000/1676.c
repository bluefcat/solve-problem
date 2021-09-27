#include <stdio.h>
#define MIN(X, Y) ((X) > (Y)?(Y): (X))

int main(){
	int two_count = 0, five_count = 0;	
	
	int n;
	int result = 0;

	scanf("%d", &n);

	for(int i = 1; i <= n; i ++){
		for(int t = i; t % 2 == 0; t >>= 1){
			two_count ++;
		}

		for(int t = i; t % 5 == 0; t /= 5){
			five_count ++;
		}


	}
	
	result = MIN(two_count, five_count);	
	printf("%d\n", result);
	
	return 0;
}
