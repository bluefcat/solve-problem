#include <stdio.h>

int main(){
	int result = 0;
	int c[5] = { 0, };
	for(int i = 0; i < 5; i ++){
		scanf("%d", c + i);
		result += c[i]*c[i] % 10;
	}

	printf("%d\n", result % 10);

	return 0;
}
