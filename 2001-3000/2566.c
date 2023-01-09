#include <stdio.h>
#define MAX 9*9
int main(){
	int result = 0; //
	int ridx   = 0; //result's index

	for(int i = 0; i < MAX; i ++){
		int n;
		scanf("%d", &n);

		if(result <= n){
			result = n;
			ridx = i;
		}
	}

	printf("%d\n%d %d\n", result, ridx / 9 + 1, ridx % 9 + 1);
	return 0;
}
