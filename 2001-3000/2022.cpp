#include <cstdio>
#include <cmath>
#include <cfloat>

using ldouble = long double;

ldouble bisearsh(ldouble x, ldouble y, ldouble c){

	ldouble s = 0.00001, e = DBL_MAX;

	for(int i = 0; i < 10000; i ++){
		ldouble l = (s + e) / 2;

		if(x*x < l*l || y*y < l*l){
			e = l;
			continue;
		}
		ldouble xh = std::sqrt(x*x - l*l);
		ldouble yh = std::sqrt(y*y - l*l);

		ldouble xs = (l * c) / xh;
		ldouble ys = (l * c) / yh;

		if((xs + ys) > l){
			e = l;
		}
		else{
			s = l;
		}
	}
	return s;
}


int main(){
	ldouble x, y, c;
	scanf("%Lf %Lf %Lf", &x, &y, &c);
	printf("%.3Lf\n", bisearsh(x, y, c));

	return 0;
}
