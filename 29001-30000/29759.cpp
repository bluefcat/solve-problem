#include <cstdio>
#include <vector>
#include <cstdlib>

using l128 = __int128;
using ulint = unsigned long long;

inline l128 abs(l128 x){
    return (x >= 0)?x:-x;
}

l128 mpow(l128 base, l128 exp, l128 mod){
    base %= mod;
	l128 result = 1;
	while(exp){
		if(exp&1) result = (base*result) % mod;
		base = (base*base)%mod;
		exp >>= 1;
	}
	return result;
}

ulint mgcd(ulint a, ulint b){
    if(a < b){
        ulint tmp = a; a = b; b = tmp;
    }
    while(b != 0){
        ulint r = a%b;
        a = b;
        b = r;
    }
    return a;
}

bool rabin(ulint p, ulint x){
	ulint d = x-1;
	while(true){
		l128 k = mpow(p, d, x);
		if(d & 1) return (k == 1 || k == x-1);
		if(k == x-1) return true;
		d >>= 1;
	}
}

bool is_prime(ulint x){
	ulint p[] = {
		2, 3, 5, 7, 11, 13, 17, 19 ,23, 29, 31, 37
	};
	for(int i = 0; i < 12; i ++)
		if(p[i] == x) return true;

	for(int i = 0; i < 12; i ++){
		if(rabin(p[i], x) == false) return false;
	}
	return true;
}


ulint pollard_rho(l128 n){
	if(n % 2 == 0) return 2;
	if(is_prime(n)) return n;
	l128 x = rand()%(n-2)+2;
	l128 y = x;
	l128 c = rand() % 10 + 1;
	l128 g = 1;
	while(g == 1){
		x = (x*x%n+c)%n;
		y = (y*y%n+c)%n;
		y = (y*y%n+c)%n;

		g = mgcd(abs(x-y), n);
		if(g == n) return pollard_rho(n);
	}
	if(is_prime(g)) return g;
	else return pollard_rho(g);
}
			
constexpr int N = 500'001;
constexpr int M = 11;
bool prime[N];
std::vector<int> p{};
bool used[2*N+3];

int board[M*M][M*M];

void build_sieve(){
	for(int i = 0; i < N; i ++) prime[i] = true;
	int idx = 3;
	int k = 3;
	for(int i = 0; idx < N; i ++){
		if(prime[i]){ //2*i+3
			prime[idx] = false;
			for(int j = idx; N - j > k; j += k){
				prime[j] = false;
			}
		}
		idx += k;
		k += 2;
		idx += k;
	}
}

int main(){
	build_sieve();
	p.emplace_back(2);
	for(int pi = 0; pi < N; pi ++)
		if(prime[pi]) p.emplace_back(2*pi+3);

	int n;
	scanf("%d", &n);

	for(int i = 0; i < n*n; i ++){
		for(int j = 0; j < n*n; j ++){
			int tmp;
			scanf("%d", &tmp);
			board[i][j] = tmp;
			if(tmp == 0) continue;
			while(tmp != 1){
				int pi = (int)pollard_rho(tmp);
				used[pi] = true;
				tmp /= pi;
			}
		}
	}
	
	int last = 0;
	for(; last < p.size(); last ++) 
		if(!used[p[last]]) break;

	for(int i = 0; i < n*n; i ++){
		for(int j = 0; j < n*n; j ++){
			if(board[i][j] != 0 ) continue;
			board[i][j] = p[last];
			used[p[last]] = true;
			for(; last < p.size(); last ++){
				if(!used[p[last]]) break;
			}
		}
	}	
	
	for(int i = 0; i < n*n; i ++){
		for(int j = 0; j < n*n; j ++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}


	return 0;
}
