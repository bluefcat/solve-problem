#include <stdio.h>
#define MIN(X, Y) (((X) > (Y))? (Y): (X))

int array[100001];
int n, s;

int main(){
	int result = 0;
	scanf("%d %d", &n, &s);

	for(int i = 0; i < n; i ++) scanf("%d", array+i);
	
	result = n+1;
	

	int l = 0, r = 0;
	int sum = array[0];

	while(l <= r && r < n){
		if(sum < s){
			sum += array[++r];
		}
		else if(sum == s){
			result = MIN(result, r-l+1);
			sum += array[++r];
		}
		else{
			result = MIN(result, r-l+1);
			sum -= array[l++];
		}
	}

	
	printf("%d\n", result == n+1? 0: result);

	return 0;
}
