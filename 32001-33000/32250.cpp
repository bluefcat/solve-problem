#include <cstdio>
#include <algorithm>

using std::max;
using std::abs;

constexpr int N = 3000001;
bool check[N] = { false, };

int f(int n){
	if(n <= 0) return 0;
	if(n == 1 || n == 2) return 1;
	
	int result = 0;
	for(int i = 0; i < n; i ++){
		result = max(result, f(i-2) + f(n-i-2) + 1);
	}
	return result;
}

int main(){
	int x = 0, result = 0;
	scanf("%d", &x);

	result = f(x);
	
	printf("%d\n", result);

	return 0;
}
