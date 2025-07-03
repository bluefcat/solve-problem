#include <cstdio>

using lint = __int128;
constexpr lint LIMIT = 1'000'000;
constexpr int N = 1'001;

class phi{
protected:
	phi(){
		for(int i = 0; i < LIMIT; i ++) _phi[i] = i;
		for(int i = 1; i < LIMIT; i ++)
			for(int j = i+i; j < LIMIT; j += i)
				_phi[j] -= _phi[i];
	}

	static phi* _instance;
	lint _phi[LIMIT];	
public:
	static lint get(lint x){
		if(_instance == nullptr) 
			_instance = new phi();
		return _instance->_phi[x];
	}

	phi(phi&) = delete;
	void operator=(const phi &) = delete;
};

phi* phi::_instance = nullptr;

lint mpow(lint x, lint e, lint m = -1){
	lint result = 1;
	if(m == -1){
		while(e){
			if(e & 1) result *= x;
			x *= x;
			e >>= 1;
		}
		return result;
	}
	while(e){
		if(e & 1) result = (result * x) % m;
		x = (x * x) % m;
		e >>= 1;
	}
	return result;
}

lint tower(lint* arr, lint n, lint i, lint m){
	if(m == 1) return 1;
	if(n == i) return arr[i];

	lint x = mpow(arr[i], tower(arr, n, i+1, phi::get(m)));
	if(x < phi::get(m)) return x;
	return (x % m) + m;
}



int main(){
	lint arr[N];
	int t, m;
	scanf("%d %d", &t, &m);
	while(t--){
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i ++){
			long long tmp;
			scanf("%lld", &tmp);
			arr[i] = (lint)tmp;
		}
		lint e = 1;
		if(n >= 2) 
			e = tower(arr,n-1,1,m);
		printf("%lld, ", (long long)e);
		printf("%lld\n", (long long)mpow(arr[0], e) % m);
	}


	return 0;
}
