#include <stdio.h>

int main(){
	int t = 0, h = 0, w = 0, n = 0;
	
	scanf("%d", &t);

	for(int i = 0; i < t; i ++){
		scanf("%d %d %d", &h, &w, &n);
		printf("%d%02d\n", n%h==0?h:n%h, n%h==0?n/h:n/h+1);
	}
	return 0;
}
