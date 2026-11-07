#include <cstdio>
#include <cstdlib>
#define LENGTH 300000

int compare(const void* x, const void* y){
	return *(int*) x < *(int*)y;
}

int main(){
	int result = 0;
	int n;
	int arr[LENGTH] = { 0, };
	
	scanf("%d", &n);

	for(int i = 0; i < n; i ++) scanf("%d", arr+i);
	qsort(arr, n, sizeof(int), compare);

	int cut = (int)((float)n * 3.f/20.f + 0.5f);
	for(int i = cut; i < n - cut; i ++){
		result += arr[i];
	}

	printf("%d\n", (int)((float)result / (float)(n-2*cut) + 0.5));

	return 0;
}
