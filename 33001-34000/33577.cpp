#include <cstdio>

using lint = long long;
constexpr int N = 100002;

int main(){
	int n;
	lint A[N] = { 0, };
	lint S[N] = { 0, };
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%lld", A+i);
		S[i] = A[i] + S[i-1];
	}


	int k = 1;
	lint result = 0;
	lint m = 0;
	for(int i = 1; i <= n; i ++){
		if(A[i] - S[i-1] > A[k] - S[k-1]) k = i;
		
		lint loss = S[i];
		lint c = (loss - m)/(A[k] - S[k-1]);
		m += c * (A[k] - S[k-1]);
		result += c;
		if(m < loss){
			m += (A[k] - S[k-1]);
			result ++;
		}
	}

	printf("%lld\n", result);

	return 0;
}
