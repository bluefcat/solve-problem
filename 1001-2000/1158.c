#include <stdio.h>

#define QSIZE 5001

int result[QSIZE];

int queue[QSIZE];
int head, tail;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i ++){
		queue[tail] = i;
		tail = (tail + 1) % QSIZE;
	}

	int idx = 0;
	int ridx = 0;
	while(head != tail){
		int cur = queue[head];
		head = (head + 1) % QSIZE;
		idx ++;
	
		if((idx % k) == 0) result[ridx++] = cur;
		else{
			queue[tail] = cur;
			tail = (tail + 1) % QSIZE;
		}

	}

	printf("<");
	
	for(int i = 0; i < ridx-1; i ++) printf("%d, ", result[i]);

	printf("%d>\n", result[ridx-1]);

	return 0;
}
