#include <cstdio>

constexpr int N = 101;

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int n;
		int arr[N] = { 0, };
		scanf("%d", &n);

		for(int i = 0; i < n; i ++)
			scanf("%d", arr+i);

		int count = 0;
		for(int i = 0; i < n; i ++){
			for(int j = i+1; j < n; j ++){
				count += (arr[i] > arr[j]);
			}
		}
		printf("%s\n", (count & 1)?"NO":"YES");
	}

	return 0;
}
