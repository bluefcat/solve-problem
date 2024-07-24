#include <cstdio>
#include <numeric>

int main(){
	int x, y, z, w;
	scanf("%d %d", &x, &y);
	scanf("%d %d", &z, &w);

	int a = x*w+z*y;
	int b = y*w;
	int c = std::gcd(a, b);
	printf("%d %d\n", a/c, b/c);
	return 0;
}
