#include <cstdio>
#include <algorithm>
#include <climits>

using ll = long long;
constexpr int N = 1000001;
inline int left(int idx){ return ((idx << 1) + 1); }
inline int right(int idx){ return ((idx << 1) + 2); }

struct node{
	ll max, smax, min, smin, max_cnt, min_cnt;
    bool max_flag, min_flag;
};

node tree[1 << 21];
ll bree[1 << 21][2];
ll arr[N] = { 0, };

node combine(node& l, node& r){
	node result{};
	result.max_flag = false;
	result.min_flag = false;
	
	if(l.max == r.max){
		result.max = l.max;
		result.smax = std::max(l.smax, r.smax);
		result.max_cnt = l.max_cnt + r.max_cnt;
	}
	else if(l.max < r.max){
		result.max = r.max;
		result.smax = std::max(l.max, r.smax);
		result.max_cnt = r.max_cnt;
	}
	else{
		result.max = l.max;
		result.smax = std::max(l.smax, r.max);
		result.max_cnt = l.max_cnt;
	}

	if(l.min == r.min){
		result.min = l.min;
		result.smin = std::min(l.smin, r.smin);
		result.min_cnt = l.min_cnt + r.min_cnt;
	}
	else if(l.min > r.min){
		result.min = r.min;
		result.smin = std::min(l.min, r.smin);
		result.min_cnt = r.min_cnt;
	}
	else{
		result.min = l.min;
		result.smin = std::max(l.smin, r.min);
		result.min_cnt = l.min_cnt;
	}

	return result;
}

void init(int l, int r, int idx){
	if(l == r){
		tree[idx] = {arr[l], 0, arr[l], LONG_LONG_MAX, 0, 0, false, false};
        return;
	}
	int m = (l + r) >> 1;
    init(l, m, left(idx));
	init(m+1, r, right(idx));
	tree[idx] = combine(tree[left(idx)], tree[right(idx)]);	
    return;
}

void propagate_bree(int idx, bool has_child){
	if(!has_child) return;
	for(auto next: {left(idx), right(idx)}){
		bree[next][0] += 
	}
}

void propagate_max(int idx, bool has_child){
	if(has_child){
		for(auto next: {left(idx), right(idx)}){
			if(tree[next].max <= tree[idx].max) continue;
			bree[next][0] += tree[next].max_cnt;
            tree[next].max = tree[idx].max;
            tree[next].max_flag = true;
		}
	}
}

void update_max(int l, int r, int s, int e, ll k, int idx){
	if(tree[idx].flag){ 
        propagate_max(idx, l != r);
        tree[idx].flag = false;
    }
	if(r < s || e < l || tree[idx].max <= k) return;
	if(s <= l && r <= e && tree[idx].smax < k){
		tree[idx].max = k;
		bree[idx][0] += tree[idx].max_cnt;
        tree[idx].flag = true;
		propagate_max(idx, l != r);
		tree[idx].flag = false;
        return;
	}

	int m = (l + r) >> 1;
    update_max(l, m, s, e, k, left(idx));
    update_max(m+1, r, s, e, k, right(idx));
	
	tree[idx] = combine(tree[left(idx)], tree[right(idx)]);
    return;
}



ll query(int l, int r, int s, int e, int idx){
    if(bree[idx][1]){
        //propagate(idx, l != r);
		bree[idx][1] = 0;
    }
	if(r < s || e < l) return 0;
	if(s <= l && r <= e) return bree[idx][0];
	int m = (l + r) >> 1;
	return query(l, m, s, e, left(idx)) + query(m+1, r, s, e, right(idx));
}


int main(){
	int n, m;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		ll x;
		scanf("%lld", &x);
		arr[i] = x;
	}
	init(0, n-1, 0);
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		int oper, l, r; ll x;
		scanf("%d %d %d", &oper, &l, &r);
		switch(oper){
			case 1:
			scanf("%lld", &x);
			//update(0, n-1, l-1, r-1, x, 0);
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:
			printf("%lld\n", query(0, n-1, l-1, r-1, 0));
		}
	}

	return 0;
}
