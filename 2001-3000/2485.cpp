#include <cstdio>
#include <numeric>

int main(){
	int n;
	scanf("%d", &n);

	int x;
	int y;
	int g = 0;
	int s = 0;
	scanf("%d", &x);
	scanf("%d", &y);
	g = y-x;
	s += y-x;

	for(int i = 2; i < n; i ++){
		x = y;
		scanf("%d", &y);
		g = std::gcd(g, y-x);
		s += y-x;
	}
	printf("%d\n", s/g-(n-1));

	return 0;
}
