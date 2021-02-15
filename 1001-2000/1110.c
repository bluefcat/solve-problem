#include <stdio.h>

int main(){
	int n, result = 0;
	scanf("%d", &n);

	int tmp = n;
	do{
		tmp = (tmp%10)*10+((tmp/10)+(tmp%10))%10;
		result ++;
	}while(tmp != n);

	printf("%d\n", result);

	return 0;
}
