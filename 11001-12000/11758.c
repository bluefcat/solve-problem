#include <stdio.h>
#define ABS(X) (((X) > 0)? (X): -(X))
int main(){
	int x[3], y[3];

	for(int i = 0; i < 3; i ++) scanf("%d %d", x+i, y+i);

	int dy = y[2] - y[0];
	int dx = x[2] - x[0];
	int dc = dx * y[0] - dy * x[0];
	
	int type = (dy * x[1] + dc) - dx * y[1];
	
	printf("%d\n", type==0?0:type/ABS(type));


	return 0;
}
