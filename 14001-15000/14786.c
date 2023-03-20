#include <stdio.h>
#include <math.h>

double f(double a, double b, double c, double x){
	return a * x + b * sin(x) - c;
}

double df(double a, double b,  double x){
	return a + b * cos(x);
}

double newton_labson(
		double(*function)(double, double, double, double),
		double(*dfunction)(double, double, double),
		double a,
		double b,
		double c,
		double allowance
		){
	
	double cur = 0.f, next = 0.f;

	while(fabsf(function(a, b, c, cur)) > allowance){
		next = cur - (function(a, b, c, cur) / dfunction(a, b, cur));
		cur = next;
	}
	
	return cur;
}

int main(){
	double a, b, c;
	
	scanf("%lf %lf %lf", &a, &b, &c);

	printf("%.19lf\n", newton_labson(f, df, a, b, c, 0.000000001));


	return 0;
}
