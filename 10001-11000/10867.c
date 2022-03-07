#include <stdio.h>

int bucket[2002];
int base = 1000;

int main(){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		int tmp;
		scanf("%d", &tmp);
		
		bucket[tmp + base] = 1;
	}

	for(int i = 0; i < 2002; i ++){
		if(bucket[i]) printf("%d ", i - base);
	}
	printf("\n");


	return 0;
}
