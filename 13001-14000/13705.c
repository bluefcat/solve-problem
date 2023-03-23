#include <stdio.h>
#include <math.h>

long double function(long double a, long double b, long double c, long double x){
	return a * x + b * sin(x) - c;
}

long double bisection(
	long double a, long double b, long double c,
	long double(*f)(long double, long double, long double, long double),
	long double allowrance){
	
	long double left = c / a - 1.f;
	long double right = c / a + 1.f;
	long double mid = (left + right) / 2.f;	

	while(right - left > allowrance){
		mid = (left + right) / 2.f;
		long double t = f(a, b, c, mid);
		if(mid-allowrance <= left && left <= mid+allowrance) return left;
		if(mid-allowrance <= right && right <= mid+allowrance) return mid;

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
	long double a, b, c;
	
	scanf("%Lf %Lf %Lf", &a, &b, &c);
	
	long double result = bisection(a, b, c, function, pow(10, -20));
	
	result = round(result * 1000000) / 1000000;

	printf("%.6Lf\n", result);

	return 0;
}

