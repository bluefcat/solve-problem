#include <stdio.h>
#define M 1000000009
#define L 100001

int main(){
	int arr[L] = { 0, };

		int T;
		scanf("%d", &T);

		arr[0] = 1; arr[1] = 1; 
		arr[2] = 2; arr[3] = 2;
		arr[4] = 3; arr[5] = 3;
		for(int i = 6; i < L; i ++)
			arr[i] = (arr[i-6]+arr[i-4]+arr[i-2]) % M;
	
		while(T--){
			int n;
			scanf("%d", &n);
			printf("%d\n", arr[n]);
		}

	return 0;
}
