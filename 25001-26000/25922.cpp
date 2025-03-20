#include <cstdio>
#include <vector>

using lint = unsigned long long;

constexpr lint L = 100000001;

int main(){
	std::vector<lint> result{};

	int n;
	scanf("%d", &n);
	
	printf("? %lld\n", L);
	fflush(stdout);
	
	lint y;
	scanf("%lld", &y);

	while(y != 0){
		result.push_back(y % L);
		y /= L;
	}

	printf("! ");
	for(auto x: result){
		printf("%lld ", x);
	}
	printf("\n");


	return 0;
}
