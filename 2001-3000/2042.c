#include <stdio.h>

#define PARENT(X) ((X-1)>>1)
#define LCHILD(X) (2*(X)+1)
#define RCHILD(X) (2*(X)+2)

int number[1000001];
int cache[1000001];

int init(int start, int end, int n){
	if(start+1 >= end) return cache[n] = number[start];
	
	int mid = 1+(start + end) >> 1;

	return cache[n] = init(start, mid, LCHILD(n)) + init(mid, end, RCHILD(n));
}

int sum(int start, int end, int n, int l, int r){
	if(l > end || r < start) return 0;
	if(l <= start && end <= r) return cache[n];

	int mid = (start + end) >> 1;
	return sum(start, mid, LCHILD(n), l, r) + sum(mid+1, end, RCHILD(n), l, r);
}

void update(int start, int end, int n, int i, int d){
	if(i < start || i > end) return;
	cache[n] += d;
	if(start == end) return;

	int mid = (start + end) >> 1;
	update(start, mid, LCHILD(n), i, d);
	update(mid+1, end, RCHILD(n), i, d);
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 0; i < n; i ++) scanf("%d", number+i);
	init(0, n, 0);

	for(int i = 0; i < m+k; i ++){ // m+k
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if(a == 1){
			update(0, n-1, 0, b, c-1);
		}
		else if(a == 2){
			int result = sum(0, n-1, 0, b, c-1);
			printf("[%d]\n", result);
		}

	}

	return 0;
}
