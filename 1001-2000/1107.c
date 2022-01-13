#include <stdio.h>
#define MIN(X, Y) (((X) > (Y))? (Y): (X))
#define ABS(X) (((X) < 0)? -(X): (X))

int length(int x){
	int result = 0;
	do{
		x /= 10;
		result ++;
	} while(x != 0);
	return result;
}

int main(){
	int target = 0;
	int m = 0, error[10] = { 0, };
	int result = 0;

	scanf("%d", &target);
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int tmp = 0;
		scanf("%d", &tmp);

		error[tmp] = 1;
	}
	
	//base channel
	result = ABS(target-100);
	int x = 0;
	while(x != 1000001){
		int p = x;
		do{
			int n = p % 10; 
			p /= 10;
			if(error[n]) goto INC;
		}while(p != 0);

		result = MIN(result, ABS(target-x)+length(x));

		INC:
		x ++;
	}

	printf("%d\n", result);

	return 0;
}
