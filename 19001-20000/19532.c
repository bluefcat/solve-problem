#include <stdio.h>

int main(){
	int x[6];
	for(int i = 0; i < 6; i ++) scanf("%d", x + i);
	
	int a = x[0] * x[4] - x[1] * x[3];
	printf("%d %d\n", (x[2]*x[4] - x[1]*x[5])/a, (x[0]*x[5]-x[2]*x[3])/a); 
	return 0;
}
