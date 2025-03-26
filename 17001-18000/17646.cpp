#include <cstdio>
#include <cstdlib>
#include <unordered_map>

using l128 = __int128;
using ulint = unsigned long long;
using lint = long long;
using map = std::unordered_map<ulint, ulint>;

constexpr ulint MOD = 1000000000000000001l;

inline l128 ABS(l128 x){
    return (x >= 0)?x:-x;
}

ulint pow(l128 base, l128 exp, l128 mod){
	l128 result = 1;
    base %= mod;
	while(exp){
		if(exp&1) result = (base*result) % mod;
		base = (base*base)%mod;
		exp >>= 1;
	}
	return (ulint)result;
}

ulint mGCD(ulint a, ulint b){
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
	l128 k = pow(p, d, x);
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

		g = mGCD(ABS(x-y), n);
		if(g == n) return pollard_rho(n);
	}
	if(is_prime(g)) return g;
	else return pollard_rho(g);
}

std::pair<lint, lint> eea(lint x, lint y){
	lint s[2] = { 1, 0 };
	lint t[2] = { 0, 1 };
	
	while(y > 0){
		lint q = x / y;
		lint r = x % y;
		lint ns = s[0] - q * s[1];
		lint nt = t[0] - q * t[1];
		x = y, y = r;
		s[0] = s[1], s[1] = ns;
		t[0] = t[1], t[1] = nt;
	}

	return {s[0], t[0]};
}

std::pair<ulint, ulint> eGCD(ulint a, ulint b){
    if(a < b){
        ulint tmp = a; a = b; b = tmp;
    }
    while(true){
        ulint r = a%b;
		if(r == 1) return {a, b};
        a = b;
        b = r;
    }
    return {a, b};
}

ulint get_quadratic_residue(ulint p){
	for(int i = 1; i < p; i ++){
		if(pow(i, (p-1) >> 1, p) == p-1) return pow(i, (p-1) / 4, p);
	}
	return 0;
}

int main(){
	ulint p, q;
	p= 97; //9^2 + 4^2
	ulint qr = get_quadratic_residue(p);
	auto[a, b] = eGCD(p, qr);
	printf("%lld %lld %llu\n", a, b, a*a+b*b);

	//for(ulint i = n+1; i < pow(2*n, 5, MOD); i ++){
	//	if(is_prime(i) && n-1 == i % n && i % 4 == 1){
	//		printf("%llu\n", i);
	//		break;
	//	}	
	//}
	
	return 0;
	/*
	map m{};
	scanf("%llu", &n);
	q = n;	
	while(n > 1){
		ulint p = pollard_rho(n);
		m[p] ++;
		n /= p;
	}
	//case 1: check square
	bool flag = true;
	ulint x = 1, y = 1, z = 1, w = 1;
	for(auto& [p, e]: m){
		if(e & 1){
			flag = false;
			break;
		}	
		x *= pow(p, e>>1, MOD);
	}
	if(flag){
		printf("1\n");
		printf("%llu\n", x);
		return 0;
	}

	//case 2: check sum of two square
	flag = true;
	for(auto& [p, e]: m){
		if(e & 1 && (p % 4) == 3){
			flag = false;
			break;
		}
	}
	if(flag){
		printf("2\n");
		printf("%llu %llu\n", x, y);
		return 0;
	}
	//case 3: check sum of three square
	flag = true;
	while(q % 4 == 0)
		q /= 4;
	if(q >= 7 && (q-7) % 8 == 0) flag = false;

	if(flag){
		printf("3\n");
		printf("%llu %llu %llu\n", x, y, z);
		return 0;
	}
	

	//n can be represent 4 square number by lagrange's four-square theorem
	printf("4\n");
	printf("%llu %llu %llu %llu\n", x, y, z, w);
	return 0;
*/
}
