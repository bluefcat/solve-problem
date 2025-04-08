#include <stdio.h>
#include <math.h>

#define N 100

_Float128 pi; 

_Float128 sint(_Float128 x){
	return (_Float128)sinl((long double)x);
	_Float128 result = 0;
	_Float128 e = x;	
	_Float128 b = 1;
	for(_Float128 i = 1; i < N; i ++){
		result += b*e;
		e *= (x*x)/(2*i * (2*i+1));
		b *= -1;
	}
	return result;
}


_Float128 function(_Float128 a, _Float128 b, _Float128 c, _Float128 x){
	return a * x + b * sint(x) - c;
}

_Float128 bisection(
	_Float128 a, _Float128 b, _Float128 c,
	_Float128(*f)(_Float128, _Float128, _Float128, _Float128)
	){
	
	_Float128 left = (c / a) - (_Float128)(1);
	_Float128 right = (c / a) + (_Float128)(1);
	_Float128 mid = (left + right) / (_Float128)2;	

	for(int i = 0; i < 1000; i ++){
		mid = (left + right) / (_Float128)2;
		_Float128 t = f(a, b, c, mid);
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
	pi = (_Float128)acosl(-1);
	long double a, b, c;
	
	scanf("%Lf %Lf %Lf", &a, &b, &c);
	
	_Float128 result = bisection(
		(_Float128)a, 
		(_Float128)b, 
		(_Float128)c, 
		function
	);

	long long x = (long long)(result *10e6);
	long double y = 0;
	if(x % 10 >= 5) y = (long double)(x/10) + 1;
	else y = (long double)(x/10);

	printf("%Lf\n", y / 10e5);

	return 0;
}

