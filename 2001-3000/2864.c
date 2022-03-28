#include <stdio.h>
#include <string.h>

int main(){
	char a[7], b[7];
	scanf("%s %s", a, b);

	int fa = 0, fb = 0, sa = 0, sb = 0;

	char* x = a;
	while(*x){
		int n = *x - '0';
		fa = fa*10 + ((n == 6)? 5: n);
		sa = sa*10 + ((n == 5)? 6: n);
		x ++;	
	}
	
	x = b;
	while(*x){
		int n = *x - '0';
		fb = fb*10 + ((n == 6)? 5: n);
		sb = sb*10 + ((n == 5)? 6: n);
		x ++;	
	}
	
	printf("%d %d\n", fa + fb, sa + sb);
	
	return 0;
}
