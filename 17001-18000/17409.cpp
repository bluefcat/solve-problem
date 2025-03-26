#include <cstdio>
#define MOD 1000000000+7
#define N 100001
int search(int* arr, int sidx, int eidx, int x){
	while(1){
		if(sidx == eidx) return sidx;
		int midx = (sidx + eidx) >> 1;
		if(arr[midx] == x) return midx;
		if(arr[midx] < x){
			sidx = midx+1;
		}
		else{
			eidx = midx;
		}
	};
	
	return sidx;
}
int main(){
	int arr[N] = { 0, };
	int count[N] = { 0, };
	int result[N] = { 0, };
	int n, l;
	scanf("%d %d", &n, &l);
	for(int i = 0; i < n; i ++) scanf("%d", arr+i);


	int length = 1;
	int max_length = 1;
	int idx = 1;
	count[0] = length;
	result[0] = arr[0];	
		
	for(int i = 1; i < n; i ++){
		if(result[idx-1] < arr[i]){
			count[i] = (length++) + 1;
			result[idx++] = arr[i];
		}
		else{
			int p = search(result, 0, idx-1, arr[i]);
			result[p] = arr[i];
			count[i] = p+1;
		}
		if(max_length < count[i]) max_length = count[i];
	}

	idx = 0;
	int a = 0;
	for(int i = 0; i < n; i ++){
		printf("%d\n", count[i] > l);
		a = (a + (count[i] >= l)) % MOD;
	}

	printf("%d\n", a);

	return 0;
}
