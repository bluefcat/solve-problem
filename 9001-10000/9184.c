#include <stdio.h>

int cache[21][21][21];

int f(int x, int y, int z){
	if(x <= 0 || y <= 0 || z <= 0) return 1;
	if(x > 20 || y > 20 || z > 20) return f(20, 20, 20);

	if(cache[x][y][z]) return cache[x][y][z];

	if(x < y && y < z) cache[x][y][z] = f(x, y, z-1) + f(x, y-1, z-1) - f(x, y-1, z);
	else cache[x][y][z] = f(x-1, y, z)+f(x-1,y-1,z)+f(x-1,y,z-1)-f(x-1,y-1,z-1);

	return cache[x][y][z];
}

int main(){
	int x, y, z;
	while(1){
		scanf("%d %d %d", &x, &y, &z);
		if(x == -1 && y == -1 && z == -1) break;

		printf("w(%d, %d, %d) = %d\n", x, y, z, f(x, y, z));
	}
	return 0;
}
