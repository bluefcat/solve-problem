#include <cstdio>

int main(){
	int n = 0;
	int r = 0;
	char first[10] = { 0, };
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int x;
		scanf("%d", &x);
		r ^= x;
	}
	scanf("%s", first);

	if(r){
		printf("%s\n", first);
		return 0;
	}
	
	printf("%s\n", first[0]=='W'?"Blackking":"WhiteKing");

	return 0;
}
