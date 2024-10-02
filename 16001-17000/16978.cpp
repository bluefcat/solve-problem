#include <cstdio>

using lint = long long;

struct node{
	node *left, *right;
	lint value;

	node(lint v = 0):left(nullptr), right(nullptr), value(v){}
};

constexpr int N = 100001;
constexpr int M = 100001;

lint arr[N];
node* history[M];

lint init(node* cur, int l, int r){
	if(l == r)
		return cur->value = arr[l];
	int m = (l + r) >> 1;
	cur->left = new node();
	cur->right = new node();
	return cur->value = init(cur->left, l, m) + init(cur->right, m+1, r);
}

lint update(node* prev, node* cur, int l, int r, int k, lint value){
	if(l == r){
		return cur->value = value;
	}

	int m = (l + r) >> 1;
	if(k <= m){ //update left
		cur->left = new node();
		cur->right = prev->right;
		return cur->value = update(prev->left, cur->left, l, m, k, value) +
							cur->right->value;
	}
	else{ //update right
		cur->right = new node();
		cur->left = prev->left;
		return cur->value = update(prev->right, cur->right, m+1, r, k, value) +
							cur->left->value;
	}
}

lint query(node* cur, int l, int r, int s, int e){
	if(r < s || e < l) return 0;
	if(s <= l && r <= e) return cur->value;
	int m = (l + r) >> 1;
	return query(cur->left, l, m, s, e) +
		   query(cur->right, m+1, r, s, e);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%lld", arr+i);

	history[0] = new node();
	init(history[0], 0, n-1);

	int m, cur = 0;
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int oper, x, y, z;
		scanf("%d %d %d", &oper, &x, &y);
		switch(oper){
			case 1:
				history[++cur] = new node();
				update(history[cur-1], history[cur], 0, n-1, x-1, y);
				break;
			case 2:
				scanf("%d", &z);
				printf("%lld\n", query(history[x], 0, n-1, y-1, z-1));
				break;
		}
	}
	return 0;
}
