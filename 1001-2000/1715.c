#include <stdio.h>

#define MAXC 100001
#define PARENT(X) ((X-1)/2)
#define LEFT(X) ((X<<1)+1)
#define RIGHT(X) ((X<<1)+2)
int heap[MAXC];
int length = 0;

void swap(int* x, int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}

void push(int x){
	heap[length++] = x;

	int i = length-1;
	while(i > 0){
		if(heap[i] < heap[PARENT(i)]){
			swap(heap + i, heap + PARENT(i));
			i = PARENT(i);
		}
		else{
			return;
		}
	}
	return;
}

int pop(){
	if(length == 0) return 0;

	int result = heap[0];
	length --;
	
	heap[0] = heap[length];
	
	int cur = 0;
	int tmp = cur;

	while(cur < length){
		if(LEFT(cur) >= length) break;

		if(heap[LEFT(cur)] < heap[cur]){
			tmp = LEFT(cur);
		}

		if(heap[RIGHT(cur)] < heap[tmp]){
			tmp = RIGHT(cur);
		}
		
		if(tmp == cur) break;

		swap(heap + cur, heap + tmp);
		cur = tmp;
	}


	return result;
}

int main(){
	int answer = 0;

	int n;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		int x;
		scanf("%d", &x);
		push(x);
	}

	while(length != 1){
		int t1 = pop(), t2 = pop();
		int tmp = t1 + t2;
		answer += tmp;
		push(tmp);
	}

	printf("%d\n", answer);
	return 0;
}
