#include <stdio.h>

int main(){
	int n, max = 0;
	int bucket[10001];

	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		int temp;
		scanf("%d", &temp);
		if(max < temp) max = temp+1;
		bucket[temp] ++;
	}
	
	for(int i = 0; i < max; i ++){
		for(int j = 0; j < bucket[i]; j ++) printf("%d ", i);
	}

	return 0;
}
