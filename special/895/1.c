#include <stdio.h>

int main(){
	int result = 0;

	int n = 0;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		char str[10] = {0,};
		int day = 0;
		scanf("%2c%d", str, &day);
		if(-1*day <= 90) result ++;
	}

	printf("%d\n", result);

	return 0;
}
