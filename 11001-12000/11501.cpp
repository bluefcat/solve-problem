#include <cstdio>
#include <vector>
#include <cmath>

using lint = long long;
constexpr int N = 1'000'001;
lint arr[N] = { 0, };
lint max[N] = { 0, };

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i ++){ 
			scanf("%lld", arr+i);
		}
		
		max[n-1] = arr[n-1];
		for(int i = n-2; i >= 0; i --)
			max[i] = std::max(max[i+1], arr[i]);


		lint result = 0;
		for(int i = 0; i < n; i ++){
			result += std::max((lint)0, max[i] - arr[i]);
		}
		printf("%lld\n", result);
	}
	return 0;
}
