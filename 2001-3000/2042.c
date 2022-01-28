#include <stdio.h>

long long number[1000002];
long long map[4000005];

long long build(int start, int end, int node){
	if(start == end) return map[node] = number[start];

	int mid = (start + end) >> 1;

	return map[node] = build(start, mid, node<<1) + build(mid+1, end, (node<<1)+1);
}

long long sum(int start, int end, int node, int left, int right){
	if(right < start || end < left) return 0;

	if(left <= start && end <= right) return map[node];

	int mid = (start + end) >> 1;

	return sum(start, mid, node<<1, left, right) + sum(mid+1, end, (node<<1)+1, left, right);
}

void update(int start, int end, int node, int index, long long diff){
	if(index < start || index > end) return;

	map[node] += diff;
	if(start == end) return;

	int mid = (start + end) >> 1;

	update(start, mid, node << 1, index, diff);
	update(mid+1, end, (node << 1) + 1, index, diff);
}



int main(){
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	long long tmp = 0;
	for(int i = 0; i < n; i ++){
		scanf("%lld", number+i);
	}
	
	build(0, n-1, 1);

	for(int i = 0; i < m+k; i ++){
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		
		switch(a){
			case 1:{
				update(0, n-1, 1, b-1, c-number[b-1]);
				number[b-1] = c;
				break;
			}
			case 2:{
				printf("%lld\n", sum(0, n-1, 1, b-1, c-1));
				break;
			}
		}
	}

	return 0;
}
