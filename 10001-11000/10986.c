#include <stdio.h>
#define MAX 1000001
#define CMAX 1001

int main(){
	unsigned long long int arr[MAX] = { 0, };
	unsigned long long int tmp[CMAX] = { 0, };
	int n, m;

	unsigned long long result = 0;

	scanf("%d %d", &n, &m);

	scanf("%lld", arr);
	arr[0] %= m;
	tmp[arr[0]] ++;

	for(int i = 1; i < n; i ++){
		scanf("%lld", arr+i);

		arr[i] += arr[i-1];
		arr[i] %= m;

		tmp[arr[i]] ++;
	}
	
	result = (unsigned long long)tmp[0];

	for(int i = 0; i < m; i ++){
		unsigned long long x = tmp[i];
		result += x * (x - 1) / 2;
	}

	printf("%lld\n", result);
	

	return 0;
}
