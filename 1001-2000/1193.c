#include <stdio.h>

int main(){
	int num = 1, den = 1, s = 0;
	int move[4][2] = {{0, 1}, {1, -1}, {1, 0}, {-1, 1}};
	
	int x = 0;
	scanf("%d", &x);

	for(int i = 0; i < x-1; i ++){
		num += move[s][0]; den += move[s][1];
		if(num == 1 || den == 1) s = (s+1)%4;
	}
	
	printf("%d/%d\n", num, den);

	return 0;
}
