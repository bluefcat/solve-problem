using lint = long long;

constexpr int N = 10;

struct node{
	node *left = nullptr, *right = nullptr;
	lint value = 0;
};

node* history[N];
lint arr[N];

lint init(node* cur, int l, int r){
	if(l == r) return cur->value = arr[l];
	int m = (l + r) >> 1;
	if(!cur->left) cur->left = new node();
	if(!cur->right) cur-> right = new node();
	return cur->value = init(cur->left, l, m) + init(cur->right, m+1, r);
}

lint update(node* prev, node* cur, int l, int r, int k, int v){
	if(l == r){
		return cur->value = v;
	}

	int m = (l + r) >> 1;
	if(k <= m){ // update left
		cur->left = new node();
		cur->right = prev->right;
		return cur->value = update(prev->left, cur->left, l, m, k, v) + cur->right->value;
	}
	//update right
	cur->right = new node();
	cur->left = prev->left;
	return cur->value = update(prev->right, cur->right, m+1, r, k, v) + cur->left->value;
}

lint query(node* cur, int l, int r, int s, int e){
	if(r < s || e < l) return 0;
	if(s <= l && r <= e) return cur->value;
	int m = (l + r) >> 1;
	return query(cur->left, l, m, s, e) + query(cur->right, m+1, r, s, e);
}


