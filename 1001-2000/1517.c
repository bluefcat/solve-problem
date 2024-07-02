#include <stdio.h>
#define N 500001

static inline int parent(int x){
	return (x-1) >> 1;
}

static inline int left(int x){
	return (((x) << 1) + 1);
}

static inline int right(int x){
	return (((x) << 1) + 2);
}

typedef struct _E{
	int x;
	int p;
} E;

E heap[N];

void swap(E* x, E* y){
	E tmp = *x; 
	*x = *y;
	*y = tmp;
}

void heapify(int size, int idx, int k){
	int l = left(idx);
	int r = right(idx);
	int t = idx;

	if(l < size && heap[l].x > heap[t].x) t = l;
	if(r < size && heap[r].x > heap[t].x) t = r;
	if(t != idx){
		swap(heap+idx, heap+t);
		heapify(size, t, k);
	}
	return;
}

void build_heap(int size){
	for(int i = size/2; i >= 0; i--)
		heapify(size, i, N+1);
	return;
}

int main(){
	int n, result = 0;
	scanf("%d", &n);
	//n = 5;
	for(int i = 0; i < n; i ++){
		int x = n-i;
		scanf("%d", &x);
		heap[i].x = x;
		heap[i].p = i;
	}

	build_heap(n);
	int size = n;	
	int prev = -1;
	for(int i = 0; i < n; i ++){
		printf("[%d:%d]", heap[0].x, heap[0].p);
		result += size - heap[0].p;
		size--;
		swap(heap+0, heap + size);
		heapify(size, 0, heap[0].p);
	}
	
	printf("%d\n", result);

	return 0;
}
