#include <stdio.h>
#define MIN(X, Y) (((X) < (Y))?(X): (Y))

int main(){
	int min = 0xFF, sum = 0;
	
	for(int i = 0; i < 7; i ++){
		int tmp = 0;
		scanf("%d", &tmp);
			
		if(tmp & 1){
			min = MIN(min, tmp);
			sum += tmp;
		}
	}

	if(min != 0xFF){
		printf("%d\n%d\n", sum, min);
	}
	else{
		printf("-1\n");
	}


	return 0;
}
