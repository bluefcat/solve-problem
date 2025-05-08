#include <cstdio>
#include <cstdlib>

using lint = long long;

constexpr lint N = 10'000'01;

int mobius[N] = { 0, 1, };

void build_mobius(){
	for(int i = 1; i <= N; i ++){
		for(int j = 2; i*j <= N; j ++) mobius[i*j] -= mobius[i];
	}
}

lint S(lint n, lint m){
	lint result = 0;
	for(lint d = 1; d <= n; d ++){
		result += mobius[d] * (m/d) * (n/d);
	}
	return result;
}

int main(){
	build_mobius();
	lint t;
	scanf("%lld", &t);
	while(t--){
		lint a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", S(a, b) + (a*b == 0 && a+b > 0) + 2*(a*b != 0));
	}
	return 0;
}
