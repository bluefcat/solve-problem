#include <cstdio>

using lint = long long;

constexpr lint pow(lint x, lint e){
	lint result = 1;	
	lint base = x;
	while(e){
		if(e & 1) result *= base;	
		base *= base;
		e >>= 1;
	}
	return result;
}

constexpr lint N = pow(10, 12);


int main(){
	printf("%lld\n", pow(10, 12));

	return 0;
}
