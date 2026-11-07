#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int binary_search(int* tree, int n, int max, int target){
	int low = 0, high = max;
	int mid = 0;
	int result = 0;

	while(low <= high){
		mid = (low + high) >> 1;
		int tmp = 0;
		for(int i = 0; i < n; i ++)
			tmp += MAX(0, tree[i] - mid);

		if(tmp >= target){
			result = MAX(result, mid);
			low = mid + 1;
		}
		else{
			high = mid-1;
		}
	}
	return result;
}

int main(){
	int n, m, max = 0;
	int tree[1000000] = { 0, };
	
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i ++){
		scanf("%d", tree+i);
		max = MAX(tree[i], max);
	}

	printf("%d\n", binary_search(tree, n, 20, m));
	return 0;
}
