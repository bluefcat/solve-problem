#include <cstdio>
#include <algorithm>
using lint = long long;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		lint a, b;
		scanf("%lld %lld", &a, &b);

		printf("A: %llb\nB: %llb\n", a, b);
		printf("%llb\n%llb\n", std::max(a-b, b-a), a^b);

	}

	return 0;
}
