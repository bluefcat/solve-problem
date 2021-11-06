#include <stdio.h>

int result;
int n, s, m;
int arr[21];

int mpow(int base, int e){
	int result = 1;
	for(int i = 0; i < e; i ++){
		result *= base;
	}
	return result;
}

int main(){
	scanf("%d %d", &n, &s);
	m = mpow(2, n)-1;
	for(int i = 0; i < n; i ++) scanf("%d", arr+i);
	
	for(int flag = 1; flag <= m; flag ++){
		
		int sum = 0, c = flag;
		for(int i = 0; i < n; i ++){
			if(c & 1) sum += arr[i];
			c >>= 1;
		}
		
		if(sum == s) {
			result ++;
		}
	}

	printf("%d\n", result);
	
	return 0;
}
