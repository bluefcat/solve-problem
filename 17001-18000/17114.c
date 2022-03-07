#include <stdio.h>
#define DIM 11
#define QSIZE 1000001

int cache[1000001];
int dim[DIM];

//idx 0 = position
//idx 1 = time
int queue[QSIZE][2];
int head, tail;

int product(int* n){
	int result = 1;
	for(int i = 0; i < DIM; i ++) result *= n[i];
	return result;
}

void get_idx(int target, int* n){
	int cnt = 0;
	
	for(int i = 0; i < DIM; i ++){
		n[i] = target % dim[i];
		target /= dim[i];
	}
}

int get_num(int* n){
	int result = n[0];
	for(int i = 1; i < DIM; i ++) result += n[i] * dim[i-1];
	return result;
}

void push(int p, int t){
	queue[tail][0] = p;
	queue[tail][1] = t;
	tail = (tail + 1) % QSIZE;
	return;
}

void pop(int* p, int* t){
	*p = queue[head][0];
	*t = queue[head][1];

	head = (head + 1) % QSIZE;
}

void ripe(int p, int t){
	if(cache[p] != 0) return;

	cache[p] = 1;
	push(p, t+1);
	return;
}

int main(){
	int result = 0;
	//dimension information
	for(int i = 0; i < DIM; i ++) scanf("%d", dim+i);

	for(int i = 0; i < product(dim); i ++){
		int tmp;
		scanf(" %d", &tmp);
		cache[i] = tmp;
		if(cache[i] == 1) push(i, 0);
	}

	while(head != tail){
		int p = 0, t = 0;
		pop(&p, &t);

		result = t > result ? t: result;

		//check boundary
		for(int i = 0; i < DIM; i ++){
			int tmp[DIM] = { 0, };
			
			get_idx(p, tmp); tmp[i] -= 1;
			if(0 <= tmp[i]) ripe(get_num(tmp), t);

			get_idx(p, tmp); tmp[i] += 1;
			if(tmp[i] < dim[i]) ripe(get_num(tmp), t);
		}

	}
	
	for(int i = 0; i < product(dim); i ++){
		printf("%d ", cache[i]);
	}

	//for(int i = 0; i < product(dim); i ++) if(cache[i] == 0) result = -1;
	printf("%d\n", result);

	return 0;
}
