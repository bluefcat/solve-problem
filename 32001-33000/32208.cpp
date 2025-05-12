#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if((x+y+z) & 1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}
