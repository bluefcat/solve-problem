#include <stdio.h>

int main(){
	int a = 0, b = 0, v = 0;
	int result = 0;
	scanf("%d %d %d", &a, &b, &v);

	result = (v-b)/(a-b);
	if((v-b) % (a-b)) result ++;

	printf("%d\n", result);

	return 0;
}
