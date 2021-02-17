#include <stdio.h>

int gcd(int x, int y){
	return (x%y)? gcd(y, x%y): y;
}

int main(){
	int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i ++){
        int x, y;
        scanf("%d %d", &x, &y);

        printf("%d\n", x*y/gcd(x, y));
    }
	return 0;
}
