#include <cstdio>
struct excinfo{
	long long BTC;
	long long ETH;
};


long long gcd(long long a, long long b){
	return b? gcd(b, a % b): a;
}

excinfo extgcd(long long a, long long b){
	excinfo res, im;
	if(!b){
		res.BTC = 1, res.ETH = 0;
		return res;
	}
	im = extgcd(b, a%b); long long q = a/b;
	res.BTC = im.ETH; res.ETH=im.BTC-q*res.BTC;
	return res;
}

excinfo Exchange(long long k){
	long long BTC = 2;
	long long ETH = 3;
	excinfo kinf = extgcd(BTC, ETH);
	excinfo A; A.BTC = kinf.BTC * k; A.ETH = kinf.ETH * k;
	if(A.BTC < 0){
		long long t = (-A.BTC)/ETH;
		A.BTC += t*ETH, A.ETH -= t*BTC;
		if(A.BTC < 0) A.BTC += ETH, A.ETH -= BTC;
	}

	if(A.ETH < 0){
		long long t = (-A.ETH)/BTC;
		A.BTC -= t*ETH, A.ETH += t*BTC;
		if(A.ETH < 0) A.BTC -= ETH, A.ETH += BTC;
	}
	if(A.BTC < 0) A.BTC = A.ETH = -1;
	return A;
}
//#include "ethereum.h"

excinfo GetExchangePrice(){
	excinfo result;
	long long k1 = 99'999'999;
	long long k2 = 100'000'000;
	excinfo p = Exchange(k1);
	excinfo q = Exchange(k2);
	
	long long id = p.BTC * q.ETH - p.ETH * q.BTC;
	result.BTC = (q.ETH * k1 - p.ETH * k2)/id;
	result.ETH = (-q.BTC * k1 + p.BTC * k2)/id;
	return result;
}

int main(){
	excinfo r = GetExchangePrice();
	printf("%lld %lld\n", r.BTC, r.ETH);
	return 0;
}
