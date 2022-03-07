#include <stdio.h>
#define ABS(X) (((X) >= 0)? (X): -(X))
int main(){
	double result = 0;
	
	double x0, y0;
	double x, y;
	double nx, ny;

	int n;
	scanf("%d", &n);

	scanf("%lf %lf", &x, &y);
	x0 = x; y0 = y;

	for(int i = 0; i < n-1; i ++){

		scanf("%lf %lf", &nx, &ny);
		
		result += x * ny - y * nx;
		
		x = nx; y = ny;
	}

	result += x * y0 - y * x0;

	printf("%.1lf\n", ABS(0.5*result));

	return 0;
}
