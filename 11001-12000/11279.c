#include <stdio.h>

int heap[100001];
int size = 0;

void insertMaxHeap(int* heap, int item){
	int i = ++size;

	while((i != 0) && (item > heap[i/2])){
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = item;
}

int deleteMaxHeap(int* heap){
	if(size == 0){
		return 0;
	}
	int p = 0, c = 1;
	int result = heap[0];
	int tmp = heap[size--];

	while(c <= size){
		if((c < size) && (heap[c] < heap[c+1])) c ++;
		if(tmp >= heap[c]) break;
	
		heap[p] = heap[c];
		p = c;
		c *= 2;
	}

	heap[p] = tmp;

	return result;
}

int main(){
	int n = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; i ++){
		int op = 0;
		scanf("%d", &op);
		
		if(op == 0){
			printf("%d\n", deleteMaxHeap(heap));
		}
		else{
			insertMaxHeap(heap, op);
		}

	}
	return 0;
}
