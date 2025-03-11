#include <cstdio>
#include <utility>

using lint = long long;

int main(){
	int t = 0;
	scanf("%d", &t);

	while(t--){
		lint m, n, x, y;
		lint result = 0;
		scanf("%lld %lld %lld %lld", &m, &n, &x, &y);
		x --; y --;
		if(m < n){
			std::swap(m, n);
			std::swap(x, y);
		}

		lint i = 0;
		for(; i*m + x <= m*n; i ++){
			if(y == ((i*m+x) % n)){
				result = i * m + x;	
				break;
			}
		}

		if(i*m+x > m*n) result = -2;
		printf("%lld\n", result + 1);

	}
	return 0;
}
