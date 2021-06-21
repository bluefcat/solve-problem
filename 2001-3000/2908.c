#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int main(){
	char tmp_a[4];
	char tmp_b[4];

	int a = 0, b = 0, idx = 1;

	scanf("%s %s", tmp_a, tmp_b);
	
	char* pa = tmp_a;
	char* pb = tmp_b;

	while(*pa){
		a += ((*pa)-'0')*idx;
		b += ((*pb)-'0')*idx;
		idx *= 10;
		pa ++;
		pb ++;
	}

	printf("%d\n", MAX(a, b));
	
	return 0;
}
