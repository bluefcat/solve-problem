#include <cstdio>
using lint = long long;
constexpr int N = 501;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		lint arr[N] = { 0, };
		scanf("%d", &n);
		for(int i = 0; i < n; i ++)
			scanf("%lld", arr+i);

		lint sum = 0;
		for(int i = 0; i < n; i ++){
			sum += arr[i] ^ arr[(i+1) % n];
		}
		printf("%lld\n", sum);
	}
	return 0;
}
