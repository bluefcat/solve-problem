#include <cstdio>
#include <cstdlib>

using lint = long long;

constexpr lint N = 10'000'001;

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
	lint a, b, c, d;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	printf("%lld\n", S(b, d) - S(b, c-1) - S(a-1, d) + S(a-1, c-1));
	return 0;
}
