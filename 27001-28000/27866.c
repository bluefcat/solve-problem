#include <stdio.h>

int main(){
	char str[1001] = { 0, };
	int n = 0;
	scanf("%s", str);
	scanf("%d", &n);
	printf("%c\n", str[n-1]);
	return 0;
}
