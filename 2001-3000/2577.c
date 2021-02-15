#include <stdio.h>

int main(){
	int count[10] = { 0, };
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int x = a*b*c;
	while(x){
		count[x%10] ++;
		x /= 10;
	}

	for(int i = 0; i < 10; i ++){
		printf("%d\n", count[i]);
	}
}
