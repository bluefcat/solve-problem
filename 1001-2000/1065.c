#include <stdio.h>

int isHan(int x){
	int r = x;
	int a0 = r % 10; r /= 10;
	int a1 = r % 10; r /= 10;
	int c = a1 - a0;

	while(r){
		int k = r % 10;
		if(k-a1 != c) return 0;
		a1 = k;
		r /= 10;
	}
	return 1;
}

int main(){
	int x = 0;
	scanf("%d", &x);
	int result = 0;
	for(int i = 1; i <= x; i ++) result += isHan(i);  
	
	printf("%d\n", result);

	return 0;
}
