#include <stdio.h>

int main(){
	int a[3] = { 0, };
	scanf("%d %d %d", a, a+1, a+2);
	
	for(int i = 0; i < 3; i ++){
		for(int j = i; j < 3; j ++){
			if(a[i] > a[j]){
				a[i] ^= a[j] ^= a[i] ^= a[j];
			}
		}
	}

	printf("%d %d %d\n", a[0], a[1], a[2]);

	return 0;
}
