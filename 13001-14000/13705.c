#include <stdio.h>
#include <math.h>

double function(double a, double b, double c, double x){
	return a * x + b * sin(x) - c;
}

double bisection(
	double a, double b, double c,
	double(*f)(double, double, double, double),
	double allowrance){
	
	double left = c / a - 1.f;
	double right = c / a + 1.f;
	double mid = (left + right) / 2.f;	

	while(right - left > allowrance){
		mid = (left + right) / 2.f;
		double t = f(a, b, c, mid);
		if(t > 0){
			right = mid;
		}
		else if(t < 0){
			left = mid;
		}
		else{
			break;
		}
	}


	return mid;
}

int main(){
	double a, b, c;
	
	scanf("%lf %lf %lf", &a, &b, &c);
	
	double result = bisection(a, b, c, function, pow(10, -14));
	
	result = round(result * 1000000) / 1000000;

	printf("%.6lf\n", result);

	return 0;
}

