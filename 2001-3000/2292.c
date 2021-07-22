#include <stdio.h>

int main(){
	int n = 0, c = 0, result = 0;
	scanf("%d", &n);

	long tmp = 1;
	
	while(1){
		tmp += 6*(c++);
		if(tmp >= n){
			result = c;
			break;
		}
	}

	printf("%d\n", result);

	return 0;
}
