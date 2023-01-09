#include <stdio.h>

int main(){
	int sum, n;
	scanf("%d", &sum);
	scanf("%d", &n);

	int result = 0;
	for(int i = 0; i < n; i ++){
		int price, count;
		scanf("%d %d", &price, &count);
		result += price * count;
	}

	printf("%s\n", result == sum? "Yes": "No");
	return 0;
}
