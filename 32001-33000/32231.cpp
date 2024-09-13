#include <cstdio>
#include <cmath>
#include <algorithm>

using std::sqrt;

constexpr double ep = 1e-32;

double get_c1(double x1, double y1, double x2, double y2){
	double sc = (x2*x2-2*x1*x2+x1*x1);
	double sd = (
		2*x2*x2*y1*y1 + 2*x2*x2*y2*y2 - 4*x1*x2*y1*y1 - 4*x1*x2*y2*y2 +
		2*x1*x1*y1*y1 + 2*x1*x1*y2*y2 + x2*x2*x2*x2 - 4*x1*x2*x2*x2 + 
		6*x1*x1*x2*x2 - 4*x1*x1*x1*x2 + x1*x1*x1*x1 + y1*y1*y1*y1 +
		y2*y2*y2*y2 - 2*y1*y1*y2*y2
	);
	return (2*(x2-x1))/sqrt(sd);
}

double f(double c1, double y){
	double x = sqrt(1-c1*c1*y*y)/c1;
	return x;
}

double inte(double c1, double y){
	double x = sqrt(1-c1*c1*y*y);
	return -0.5*std::log((1+x)/(1-x));
}

int main(){
	int t = 0;
	scanf("%d", &t);
	while(t--){
		double x1, y1, x2, y2;
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		if(x1 == x2){
			printf("%.6lf\n", std::abs(log(y2/y1)));
			continue;
		}

		if(x1 > x2){
			double tmp = x1;
			x1 = x2;
			x2 = tmp;
			tmp = y1;
			y1 = y2;
			y2 = tmp;
		}
		x2 = x2-x1;
		x1 = 0;

		double c1 = -get_c1(x1, y1, x2, y2);
		if(y1 > y2) c1 *= -1;
		double c2 = x2 - f(c1, y2);

		double result = 0;
		if(y1 <= y2){
			result = inte(c1, y2) - inte(c1, y1);
		}
		else{
			result = inte(c1, y1) - inte(c1, y2);
		}

		if(!(x1 - ep < f(c1, y1)+c2 && f(c1, y1)+c2 < x1 + ep)){
			if(c1 > 0)
				result = inte(c1, 1/c1) - inte(c1, y2) + inte(c1, 1/c1) - inte(c1, y1);
			else
				result = inte(c1, -1/c1) - inte(c1, y2) + inte(c1, -1/c1) - inte(c1, y1);
		}
		printf("%.6lf\n", result);
	}
	return 0;
}

