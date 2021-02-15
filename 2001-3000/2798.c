#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, m, result = 0;
	int* num;
	
	scanf("%d %d", &n, &m);

	num = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i ++){
		scanf("%d", num+i);
	}

	for(int i = 0; i < n-2; i ++){
		for(int j = i+1; j < n-1; j ++){
			for(int k = j+1; k < n; k ++){
				int sum = num[i]+num[j]+num[k];
				if(0 <= (m-sum) && (m-sum) < (m-result)) result = sum;
			}
		}
	}

	printf("%d\n", result);

	free(num);
	return 0;
}
