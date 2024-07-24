#include <cstdio>
#define N 100001
static inline int get_left(int x){
	return (x << 1) + 1;
}

static inline int get_right(int x){
	return (x << 1) + 2;
}


void preorder(int* arr, int n, int idx){
	if(n <= idx) return;
	printf("%d ", arr[idx]);
	preorder(arr, n, get_left(idx));
	preorder(arr, n, get_right(idx));
}

void postorder(int* arr, int n, int idx){
	if(n <= idx) return;
	postorder(arr, n, get_left(idx));
	postorder(arr, n, get_right(idx));
	scanf("%d", arr+idx);
}

int main(){
	int arr[N] = { 0, }; 
	
	int n = 0;
	scanf("%d", &n);
	int tmp; for(int i = 0; i < n; i ++) scanf("%d", &tmp);
	postorder(arr, n, 0);
	preorder(arr, n, 0); printf("\n");
}
