#include <cstdio>
#include <unordered_map>

using std::unordered_map;
using lint = long long;

constexpr int N = 200'001;
constexpr int get_left(int idx){
	return (idx << 1) + 1;
}
constexpr int get_right(int idx){
	return (idx << 1) + 2;
}

lint arr[N];
unordered_map<lint, lint> tree[4*N+4];

auto& init(int l, int r, int idx){
	if(l == r){
		tree[idx][arr[l]] = 1;
		return tree[idx];
	}
	
	int m = (l+r) >> 1;

	auto& lr = init(l, m, get_left(idx));
	auto& rr = init(m+1, r, get_right(idx));
	for(auto &[k, v]: lr)
		tree[idx][k] += v;
	
	for(auto &[k, v]: rr)
		tree[idx][k] += v;

	return tree[idx];

}

void propagate(int l, int r, int idx){
	if(tree[idx][-1] == 0) return;
	if(l != r){
		//update query
		tree[get_left(idx)][-1]  = tree[idx][-1];
		tree[get_right(idx)][-1] = tree[idx][-1];
	}
	tree[idx].clear();
}

auto& update(int l, int r, int s, int e, int idx){
	propagate(l, r, idx);
	if(r < s || e < l) return tree[idx];
	if(s <= l && r <= e){
		tree[idx][-1] = 1;
		propagate(l, r, idx);
		return tree[idx];
	}
	int m = (l + r) >> 1;
	auto& lr = update(l, m, s, e, get_left(idx));
	auto& rr = update(m+1, r, s, e, get_right(idx));
	tree[idx].clear();
	for(auto &[k, v]: lr)
		tree[idx][k] += v;
	
	for(auto &[k, v]: rr)
		tree[idx][k] += v;

	return tree[idx];
}

auto query(int l, int r, int s, int e, int idx){
	propagate(l, r, idx);
	if(r < s || e < l) return unordered_map<lint, lint>{};
	if(s <= l && r <= e) return tree[idx];
	int m = (l + r) >> 1;

	auto lr = query(l, m, s, e, get_left(idx));
	auto rr = query(m+1, r, s, e, get_right(idx));

	unordered_map<lint, lint> result{};
	
	for(auto &[k, v]: lr)
		result[k] += v;
	
	for(auto &[k, v]: rr)
		result[k] += v;
	return result;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%lld", arr+i);
	}

	init(0, n-1, 0);

	int q;
	scanf("%d", &q);
	while(q--){
		int oper, l, r, k;
		scanf("%d", &oper);
		switch(oper){
			case 1:
				scanf("%d %d %d", &l, &r, &k);
				l--; r--;
				printf("%lld\n", query(0, n-1, l, r, 0)[k]);
			break;
			case 2:
				scanf("%d %d", &l, &r);
				l--; r--;
				update(0, n-1, l, r, 0);
			break;
		}
	}

	return 0;
}


