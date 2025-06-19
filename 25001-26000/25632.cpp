#include <cstdio>
#include <vector>

using lint = long long;
constexpr int P = 10001;
bool is_prime[P] = { false, };
std::vector<lint> prime;

void build_sieve(){
	for(int i = 2; i < P; i ++) is_prime[i] = true;	
	for(int p = 2; p < P; p ++){
		if(is_prime[p])
			prime.emplace_back(p);
		
		for(auto& q: prime){
			if(p*q >= P) break;
			is_prime[p*q] = false;
			if(p%q == 0) break;
		}
	}
}

int get_count(int l, int r){
	int result = 0;
	for(int i = l; i <= r; i ++) result += is_prime[i];
	return result;
}

int main(){
	build_sieve();
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int t = get_count(a, b);
	int j = get_count(c, d);
	int l = 0;
	int r = 0;
	if(a <= c && c <= b) l = c;
	if(a <= d && d <= b) r = d;
	if(c <= a && a <= d) l = a;
	if(c <= b && b <= d) r = b;
	int p = get_count(l, r);

	if(p % 2 == 0){
		if(t > j)
			printf("yt\n");
		else	
			printf("yj\n");
		return 0;
	}

	if(t < j)
		printf("yj\n");
	else 
		printf("yt\n");

	return 0;
}
