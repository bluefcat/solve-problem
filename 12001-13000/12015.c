#include <stdio.h>
#define MAX(X, Y) (((X) > (Y))? (X): (Y))

int arr[1000001];
int stack[1000001];
int head;

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++) scanf("%d", arr + i);
	
	int result = 1;
	stack[head++] = arr[0];

	for(int i = 1; i < n; i ++){
		if(stack[head-1] < arr[i]){
			stack[head++] = arr[i];
			result ++;
		}
		else{
			int l = 0, r = head - 1;

			while(l < r){
				int m = (l + r) >> 1;
				if(arr[m] < arr[i]) l = m + 1;
				else r = m;
			}
 
			stack[r] = arr[i];
		}
	}

	printf("%d\n", result);

	return 0;
}
