#include <cstdio>

constexpr int N = 100001;

bool f[N] = { false, };
int s[N] = { 0, };
int size = 0;
int main(){
	for(int i = 0; i < N; i ++) f[i] = true;

	for(int i = 0; 5*i < N; i ++){
		if(!f[i]) continue;
		f[3*i] = false;
		f[5*i] = false;
	}

	for(int i = 0; i < N; i ++){
		if(f[i]) s[size++] = i;
	}
	printf("[%d] ", size);
	for(int i = 0; i < 100; i++){
		printf("%d, ", s[i]);
	}
	printf("\n");

	return 0;
}
