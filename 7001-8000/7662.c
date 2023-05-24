#include <stdio.h>
#define MAXN 10001

#define PARENT(X) ((X - 1) >> 1)
#define LEFT(X) ((X << 1) + 1)
#define RIGHT(X) ((X << 1) + 2)

typedef struct{
	long long x;
	int min_idx;
	int max_idx;

} node;

void move_max(int idx, node** heap, node* target){
	heap[idx] = target;
	target->max_idx = idx;
	return;
}

void move_min(int idx, node** heap, node* target){
	heap[idx] = target;
	target->min_idx = idx;
	return;
}

int max_push(long long data, node** max_heap, node** min_heap, int* length){
	if(*length >= MAXN) return 0;
	
	
}

int max_pop(node** max_heap, node** min_heap, int* length){
	if(*length == 0) return 0;
	
	node* origin = max_heap[0];
	node* target = max_heap[*length - 1];
	
	int idx = 0;
	move_max(idx, max_heap, target);
	
	while(idx > (*length - 1)){
		int next = -1;
		int left = LEFT(idx);
		int right = RIGHT(right);

		if(max_heap[left]->x < target->x){
			next = left;
		}

		if(next == left && max_heap[left]->x < max_heap[right]->x){
			next = right;
		}

		if(next == -1) break;

		node* changer = max_heap[next];

		move_max(idx, max_heap, changer);
		move_max(next, max_heap, target);
		idx = next;
	}
	
	//min change
	//int min_top = origin->min_idx;

	return 1;
}

int main(){
	node* max_heap[MAXN] = { 0, };
	node* min_heap[MAXN] = { 0, };
	int length = 0;
	
	return 0;
}
