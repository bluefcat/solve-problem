#include <stdio.h>

int main(){
	int target = 0;
	int result = 0;

	scanf("%d", &target);

	int tmp = 64;
	while(target > 0){
		
		while(target >= tmp){
			target -= tmp;
			result ++;
		}
		
		tmp >>= 1;

	}
	
	printf("%d\n", result);

	return 0;
}
