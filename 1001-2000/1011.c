#include <stdio.h>

int main(){
	int T = 0;
	scanf("%d", &T);
	for(int i = 0; i < T; i ++){
		unsigned int x, y;
		scanf("%d %d", &x, &y);
		
		// (0, y-x)
		y -= x;
		x = 0;

		unsigned int n = 1;
		for(;n*n+n < y;n ++);
		n -= 1;

		unsigned int p = y - (n*n+n);
		unsigned int result = 2*n;
		if(p <= n+1) result += 1;
		else result += 2;

		printf("%d\n", result);

	}
	return 0;
}
