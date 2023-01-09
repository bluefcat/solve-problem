#include <stdio.h>
#define MAX 100
#define INDEX(X) (X+MAX)
int main(){
	int n;
	int v[MAX * 2 + 1] = { 0, };

	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		int num;
		scanf("%d", &num);
		v[INDEX(num)] ++;
	}

	int x;
	scanf("%d", &x);

	printf("%d\n", v[INDEX(x)]);
		

	return 0;
}
