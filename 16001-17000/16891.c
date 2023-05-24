#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979

int main(){
	int n;
	scanf("%d", &n);

	printf("%d\n", (int)(PI / atan((double)1/n)));

	return 0;
}
