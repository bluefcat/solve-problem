#include <complex>
#include <vector>

using complex = std::complex<double>;
using std::vector;

constexpr double pi = 3.14159265358979;
constexpr int N = 1000001;
constexpr int Q = 200001;

void set_prime(vector<complex>& f){
	for(int i = 2; i < N; i ++){
		if(i == 2 || i & 1) f[i] = { 1, 0 };
	}
	
	for(int i = 3; i*i <= N; i +=2){
		if((int)f[i].real() == 0) continue; 
		for(int j = i*i; j < N; j+=i){
			f[j] = { 0, 0 };
		}
	}
}

void fft(vector<complex>& f, complex w){
	int n = f.size();
	if(n == 1) return;
	
	vector<complex> even(n>>1), odd(n>>1);
	for(int i = 0; i < n; i ++){
		if(i&1) odd[i>>1] = f[i];
		else even[i>>1] = f[i];
	}

	fft(even, w*w);
	fft(odd, w*w);

	complex wi(1, 0);
	for(int i = 0; i < (n >> 1); i ++){
		f[i] = even[i] + wi*odd[i];
		f[i+(n >> 1)] = even[i] - wi*odd[i];
		wi *= w;
	}
}


int main(){
	int n, size = 1;
	while(N > size) size <<= 1;
	size <<= 1;
	printf("%d\n", size);
	vector<complex> f(size, 0);
	set_prime(f);

	complex w(std::cos(2*pi/size), std::sin(2*pi/size));
	fft(f, w);
	for(int i = 0; i < size; i ++) f[i] *= f[i];
	fft(f, complex(1, 0)/w);

	for(int i = 0; i < size; i ++){
		f[i] /= complex(size, 0);
		f[i] = complex(round(f[i].real()), round(f[i].imag()));
	}

	int t = 100000;
	//scanf("%d", &t);
	while(t--){
		int x;
		x = t;
		//scanf("%d", &x);
		int result = (int)(f[x].real());
		result = (result / 2) + (result & 1);
		printf("%d\n", result);
	}

	return 0;
}
