#include <stdio.h>

int main(){
	int x, y, z;
	
	while(scanf("%d %d %d", &x, &y, &z) && (x+y+z > 0)){
		x *= x;
		y *= y;
		z *= z;

		if(x + y == z || x + z == y || z + y == x){
			printf("right\n");
		}
		else{
			printf("wrong\n");
		}
	}
	return 0;
}
