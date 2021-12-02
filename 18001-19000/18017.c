#include <stdio.h>
#include <math.h>

#define LIGHT 299792458

int main(){
	double v1;
	double v2;

	scanf("%lf %lf", &v1, &v2);

	double u = v1+v2;
	double d = 1+(v1/LIGHT * v2/LIGHT);

	printf("%.2lf\n", u/d);


	return 0;
}
