#include <cstdio>
#include <cmath>
#include <utility>

using std::sqrt;

long double get_c2(long double x1, long double y1, long double x2, long double y2){
	return ((y2*y2+x2*x2)-(y1*y1+x1*x1))/(2*(x2-x1));
}

long double get_c1(long double c2, long double x1, long double y1){
	return 1/sqrt((x1-c2)*(x1-c2)+y1*y1);
}

long double f(long double c1, long double c2, long double y){
	return sqrt(1-c1*c1*y*y)/c1+c2;
	//return sqrt(1-c1*y)*sqrt(1+c1*y*y)/c1+c2;
}

long double inte(long double c1, long double y){
	long double x = sqrt(1-c1*y)*sqrt(1+c1*y);
	return -0.5*std::log((1+x)/(1-x));
}

int main(){
	int t = 0;
	scanf("%d", &t);
	while(t--){
		long double x1, y1, x2, y2;
		scanf("%Lf %Lf %Lf %Lf", &x1, &y1, &x2, &y2);
		if(x1 == x2){
			printf("%lf\n", std::abs(log(y2/y1)));
			continue;
		}
		
		if(x1 > x2){
			std::swap(x1, x2);
			std::swap(y1, y2);
		}
		long double c2 = get_c2(x1, y1, x2, y2);
		long double c1 = get_c1(c2, x1, y1); 	//always positive

		long double result = 0.0f;

		if(x2 <= c2){
			long double s = y1, e = y2;
			if(s > e) std::swap(s, e);
			result = inte(-c1, e) - inte(-c1, s);
		}
		else if(x1 <= c2){
			result = inte(c1, 1/c1) - inte(c1, y2) + inte(-c1, 1/c1) - inte(-c1, y1);
		}
		else{
			long double s = y1, e = y2;
			if(s > e) std::swap(s, e);
			result = inte(c1, e) - inte(c1, s);
		}
		printf("%Lf\n", result);
	}
	return 0;
}

