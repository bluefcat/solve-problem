#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

using l128 = __int128;
using lint = unsigned long long;
using map = std::unordered_map<lint, lint>;

inline l128 ABS(l128 x){
    return (x >= 0)?x:-x;
}

lint pow(l128 base, l128 exp, l128 mod){
	l128 result = 1;
    base %= mod;
	while(exp){
		if(exp&1) result = (base*result) % mod;
		base = (base*base)%mod;
		exp >>= 1;
	}
	return (lint)result;
}

lint mGCD(lint a, lint b){
    if(a < b){
        lint tmp = a; a = b; b = tmp;
    }
    while(b != 0){
        lint r = a%b;
        a = b;
        b = r;
    }
    return a;
}

bool rabin(lint p, lint x){
	lint d = x-1;
	while(true){
	l128 k = pow(p, d, x);
		if(d & 1) return (k == 1 || k == x-1);
		if(k == x-1) return true;
		d >>= 1;
	}
}

bool is_prime(lint x){
	lint p[] = {
		2, 3, 5, 7, 11, 13, 17, 19 ,23, 29, 31, 37
	};
	for(int i = 0; i < 12; i ++)
		if(p[i] == x) return true;

	for(int i = 0; i < 12; i ++){
		if(rabin(p[i], x) == false) return false;
	}
	return true;
}


lint pollard_rho(l128 n){
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

int main(){
	lint n, q;
	map m{};
	scanf("%llu", &n);
	q = n;	
	while(n > 1){
		lint p = pollard_rho(n);
		m[p] ++;
		n /= p;
	}
	//case 1: check square
	bool flag = true;
	for(auto& [p, e]: m){
		if(e & 1){
			flag = false;
			break;
		}	
	}
	if(flag){
		printf("1\n");
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
		return 0;
	}
	//case 3: check sum of three square
	flag = true;
	while(q % 4 == 0)
		q /= 4;
	if(q >= 7 && (q-7) % 8 == 0) flag = false;

	if(flag){
		printf("3\n");
		return 0;
	}
	

	//n can be represent 4 square number by lagrange's four-square theorem
	printf("4\n");
	return 0;
}
