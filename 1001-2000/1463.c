#include <stdio.h>
#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int mem[1000001];

int main(){
	mem[0] = 0;
	mem[1] = 0;
	mem[2] = 1;
	mem[3] = 1;
	int n;
	scanf("%d", &n);

	for(int i = 4; i <= n; i ++){
		mem[i] = mem[i-1]+1;
		if(i%2 == 0){
			mem[i] = MIN(mem[i], mem[i/2]+1);
		}
		if(i%3 == 0){
			mem[i] = MIN(mem[i], mem[i/3]+1);
		}
	}
	
	printf("%d\n", mem[n]);

	return 0;
};
