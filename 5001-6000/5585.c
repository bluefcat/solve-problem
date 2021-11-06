#include <stdio.h>

int main(){
	int coin[] = { 500, 100, 50, 10, 5, 1 };
	int result = 0;

	int n = 0;
	scanf("%d", &n);
	n = 1000 - n;
	for(int i = 0; i < sizeof(coin) && n != 0; i ++){


		result += n / coin[i];
		n = n%coin[i];

	}

	printf("%d\n", result);

	return 0;
}
