#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
int cache[1000001];

int main(){
	long long result = 0;
	int n, b, c;

	scanf("%d", &n);

	for(int i = 0; i < n ; i ++){
		scanf("%d", cache+i);
	}

	scanf("%d %d", &b, &c);

	for(int i = 0; i < n; i ++){
		int t = MAX((cache[i]-b), 0);
		result += t/c + (t%c > 0? 1: 0);
		
	}	

	printf("%lld\n", result + n);

	return 0;
}
