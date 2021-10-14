#include <stdio.h>
#include <math.h>

int main(){
	int r;
	
	double ur, tr;

	scanf("%d", &r);
	
	ur = r*r*M_PI;
	tr = r*r*2;

	printf("%lf\n%lf\n", ur, tr);

	return 0;
}
