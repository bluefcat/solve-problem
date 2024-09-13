#include <cstdio>
#include <cmath>
#include <utility>

using std::sqrt;

double get_c2(double x1, double y1, double x2, double y2){
	return ((y2*y2+x2*x2)-(y1*y1+x1*x1))/(2*(x2-x1));
}

double get_c1(double c2, double x1, double y1){
	return 1/sqrt((x1-c2)*(x1-c2)+y1*y1);
}

double f(double c1, double c2, double y){
	return sqrt(1-c1*c1*y*y)/c1+c2;
}

double inte(double c1, double y){
	double x = sqrt(1-c1*y)*sqrt(1+c1*y);
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
			std::swap(x1, x2);
			std::swap(y1, y2);
		}
		double c2 = get_c2(x1, y1, x2, y2);
		double c1 = get_c1(c2, x1, y1); 	//always positive

		double result = 0.0f;
		if(x2 <= c2){
			double s = y1, e = y2;
			if(s > e) std::swap(s, e);
			result = inte(-c1, e) - inte(-c1, s);
		}
		else if(x1 <= c2){
			result = inte(c1, 1/c1) - inte(c1, y2) + inte(-c1, 1/c1) - inte(-c1, y1);
		}
		else{
			double s = y1, e = y2;
			if(s > e) std::swap(s, e);
			result = inte(c1, e) - inte(c1, s);
		}
		printf("%.6lf\n", result);
	}
	return 0;
}

