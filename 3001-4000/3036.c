#include <stdio.h>

int gcd(int x, int y){
	return (x%y)? gcd(y, x%y): y;
}

int main(){
	int gear[101];
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		scanf("%d", gear+i);
	}

	for(int i = 1; i < n; i ++){
		int x = gear[i];
		int g = gcd(gear[0], x);

		printf("%d/%d\n", gear[0]/g, x/g);
	}

	return 0;
}
