#include <stdio.h>

#define MAX(X, Y) ((X) > (Y)?(X): (Y))
#define FAIL 40

int main(){
	int result = 0;
	for(int i = 0; i < 5; i ++){
		int tmp = 0;
		scanf("%d", &tmp);

		result += MAX(tmp, FAIL);
	}
	
	printf("%d\n", (int)result/5);
	
	return 0;
}
