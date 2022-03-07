#include <stdio.h>
#include <math.h>

int main(){
	int D, H, W;
	int rh = 0, rw = 0;
	
	scanf("%d %d %d", &D, &H, &W);
	
	int a = W*D;
	int b = H*D;
	
	int snum = H*H + W*W;

	printf("%d %d\n", (int)(b/sqrt(snum)), (int)(a/sqrt(snum)));
	return 0;
}
