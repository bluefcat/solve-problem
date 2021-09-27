#include <stdio.h>

int fact(int n, int p){
	int result = 1;
	
	for(int i = 1; i <= n; i ++){
		result *= i;
		result %= p;
	}

	return result % p;
}

int main(){
	int result = -1;
	int min = 10001;
	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);

	for(int i = m; i <= n; i ++){
		if(i != 1 && fact(i-1, i) == i - 1) {
			if(result == -1) result = 0;
			if(min > i){
				min = i;
			}
			result += i;
		}
	}

	printf("%d\n", result);
	if(result != -1) printf("%d\n", min);

	return 0;
}
