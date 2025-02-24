#include <cstdio>
#include <climits>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

constexpr int N = 100004;
constexpr int left(int x){
	return (x << 1) + 1;
}
constexpr int right(int x){
	return (x << 1) + 2;
}

struct Node{
	int m = 0, l = 0, r = 0;
};

int arr[N];
int add[N];
Node tree[4*N+4];

Node combine(int l, int r, const Node* ln, const Node* rn){
	Node result{};
	int al = (l == 0)?0:add[l-1];
	result.l = std::max(
		ln->l, rn->l + (add[(l+r)>>1] - al)
	);
	result.r = std::max(
		rn->r, ln->r + (add[r] - add[(l+r)>>1])
	);
	result.m = std::max(
		{ln->m, rn->m, ln->r + rn->l}
	);
	return result;
}

Node* init(int l, int r, int idx){
	if(l == r){
		tree[idx] = {arr[l], arr[l], arr[l]};
		return tree + idx;
	}

	int m = (l + r) >> 1;
	Node* lp = init(l, m, left(idx));
	Node* rp = init(m+1, r, right(idx));

	tree[idx] = combine(l, r, lp, rp);
	return tree + idx;
}

Node query(int l, int r, int s, int e, int idx){
	if(r < s || e < l) return {INT_MIN, INT_MIN, INT_MIN};
	if(s <= l && r <= e) return tree[idx];	

	int m = (l + r) >> 1;
	Node lp = query(l, m, s, e, left(idx));
	Node rp = query(m+1, r, s, e, right(idx));
	
	if(lp.m == INT_MIN) return rp;
	if(rp.m == INT_MIN) return lp;

	return combine(l, r, &lp, &rp);
}

int get_answer(int l, int r){
	int cache[N] = { 0, };
	int result = INT_MIN;
	cache[0] = arr[l];
	for(int i = 1; i <= r-l; i ++){
		cache[i] = std::max(
			cache[i-1] + arr[l+i], arr[l+i]
		);
	}
	for(int i = 0; i <= r-l; i ++){
		result = std::max(result, cache[i]);
	}
	return result;
	return 1;
}

int main(){
	srand((unsigned int)time(NULL));
	int n, m;
	n = 1024;
	//scanf("%d", &n);
	int count = 0;
	while(true){
		count ++;
		printf("attempt: [%d]\n", count);
		for(int i = 0; i < n; i ++){
			arr[i] = (rand() % 21) - 10;
			//scanf("%d", arr+i);

			add[i] = arr[i];
			if(i != 0) add[i] += add[i-1]; // add[i] = add[i-1] + arr[i];
		}
		init(0, n-1, 0);

		for(int s = 1; s <= n; s ++){
			for(int e = s; e <= n; e ++){
				Node node = query(0, n-1, s-1, e-1, 0);
				int answer = node.m;
				bool a = (answer == get_answer(s-1, e-1));
				if(!a){
					for(int i = 0; i < n; i ++) printf("%d ", arr[i]); printf("\n");
					printf("query: (%d %d)", s, e);
					printf("%d != %d\n", answer, get_answer(s-1, e-1));

					printf("\n");
					return 0;
				}
			}
		}
	}


	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", query(0, n-1, s-1, e-1, 0).m);
	}

	return 0;
}
