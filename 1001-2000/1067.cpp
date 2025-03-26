#include <cstdio>
#include <complex>
#include <vector>
#include <algorithm>

using complexd = std::complex<double>;
using std::vector;

constexpr double pi = 3.14159265358979;

void fft(vector<complexd>& f, complexd w){
	int n = f.size();
	if(n == 1) return;

	vector<complexd> even(n>>1), odd(n>>1);
	for(int i = 0; i < n; i ++){
		if(i & 1) odd[i>>1] = f[i];
		else even[i>>1] = f[i];
	}

	fft(even, w*w);
	fft(odd, w*w);
	
	complexd wi(1, 0);
	for(int i = 0; i < (n >> 1); i ++){
		f[i] = even[i] + wi*odd[i];
		f[i+(n>>1)] = even[i] - wi*odd[i];
		wi *= w;
	}

}

int main(){
	int n, size = 1; 
	scanf("%d", &n);
	
	while(2*n+1 > size) 
		size <<= 1;	
	size <<= 1;
	
	complexd w(std::cos(2*pi/size), std::sin(2*pi/size));
	vector<complexd> u(size), v(size), result(size);

	for(int i = 0; i < n; i ++){
		double x;
		scanf("%lf", &x);
		u[i] = complexd(x, 0);
		u[i+n] = complexd(x, 0);
	}

	for(int i = 0; i < n; i ++){
		double x;
		scanf("%lf", &x);
		v[n-i-1] = complexd(x, 0);
	}

	fft(u, w); fft(v, w);
	for(int i = 0; i < size; i ++) result[i] = u[i] * v[i];
	fft(result, complexd(1, 0)/w);
	
	for(int i = 0; i < size; i ++){
		result[i] /= complexd(size, 0);
		result[i] = complexd(
				round(result[i].real()), 
				round(result[i].imag())
		);
	}

	
	long long answer = 0;
	for(int i = 0; i < size; i ++) answer = std::max(answer, (long long)result[i].real());
	printf("%lld\n", answer);

	return 0;
}
