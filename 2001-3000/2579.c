#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))
int stair[301];
int mem[301];

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		scanf("%d", stair+i);
	}
	
	mem[0] = stair[0];
	mem[1] = MAX(stair[0]+stair[1], stair[1]);
	mem[2] = MAX(stair[0]+stair[2], stair[1]+stair[2]);

	for(int i = 3; i < n; i ++){
		mem[i] = MAX(mem[i-2]+stair[i], mem[i-3]+stair[i-1]+stair[i]);
	}

	printf("%d\n", mem[n-1]);
	return 0;
}
