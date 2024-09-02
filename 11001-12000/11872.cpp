#include <cstdio>

using ll = long long;
int main(){
	int n = 0;
	ll g = 0;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		ll x;
		scanf("%lld", &x);
		g ^= (x+(x%4==3)-(x%4==0));
	}
	if(g != 0){
		printf("koosaga\n");
		return 0;
	}
	printf("cubelover\n");
	return 0;
}
