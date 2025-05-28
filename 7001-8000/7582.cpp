#include <cstdio>
#include <algorithm>

int main(){
	char name[25]; 
	int capa, p, s;
	scanf("%s %d %d %d", name, &capa, &p, &s);
	for(int i = 0; i < s; i ++){
		int l, b;
		scanf("%d %d", &l, &b);
		p = std::max(0, std::min(capa, p-l+b));
	}
	char x, y;
	scanf("%c %c", &x, &y);
	printf("%s %d\n", name, p);
	return 0;
}
