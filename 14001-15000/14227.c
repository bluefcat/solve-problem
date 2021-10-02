#include <stdio.h>
#define ABS(X) ((X) > 0? (X): -(X))
int main(){
	int a, b;
	int x, y;
	scanf("%d %d %d %d", &a, &b, &x, &y);

	int result = 0;
	if(a > x || b > y) goto WRONG;

	while(1){
		if(a == x && b == y) goto ANSWER;

		if(x % 2 != y % 2){
			int p = x - a, q = y - b;
			if(p != q) goto WRONG;
			result += p;
			goto ANSWER;
		}
		//x is odd
		if(x % 2){
			x --; y --; result ++;
		}
		else{
			int p = ABS((a-b)), q = ABS((x/2 - y/2));
			
			if( a <= x/2 && b <= y/2 && p <= q){
				x >>= 1, y >>=1; result ++;
			}
			else{
				p = x-a, q = y-b;
				if(p != q) goto WRONG;
				result += p;
				goto ANSWER;
			}
		}

		if(a > x || b > y) goto WRONG;
	}
	WRONG:
	result = -1;
	ANSWER:
	printf("%d\n", result);

	return 0;
}
