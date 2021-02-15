#include <stdio.h>

int main(){
	int a[15] = { 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596 };
	int n;
	scanf("%d", &n);

	printf("%d\n", a[n-1]);
	return 0;
}
