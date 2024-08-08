#include <cstdio>

int gr(int x){
	if(x&1) return 1;
	int result = 0;
	while(x % 2 == 0){
		result ++;
		x /= 2;
	}
	return result + 1;
}

int main(){
	int r, g;
	scanf("%d %d", &r, &g);
	if(gr(r)^gr(g)){
		printf("A player wins\n");
		return 0;
	}
	printf("B player wins\n");
	return 0;
}
