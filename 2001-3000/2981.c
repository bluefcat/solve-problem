#include <stdio.h>
#define MIN(X, Y) (((X) > (Y))? (Y): (X))
int mem[100];

int main(){
	int n = 0;
	int min = 1000000001;

	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		scanf("%d", mem+i);
	}
	
	for(int i = 0; i < n-1; i ++){
		for(int j = i+1; j < n; j ++){
			if(mem[j] >= mem[i]) mem[j] -= mem[i]; 
			min = MIN(min, mem[j]);
		}
	}

	if(min == 0) min = mem[0];
	
	for(int i = 0; i < n; i ++){
		printf("%d ", mem[i]);
	}
	printf("\nmin: %d\n", min);

	for(int i = 2; i <= min; i ++){
		if((mem[1] % i) == 0) printf("%d ", i);
	}
	printf("\n");
	
	return 0;
}
