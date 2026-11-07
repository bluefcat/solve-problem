#include <cstdio>
#define MAXN 1000002

using ll = long long;

ll init(ll* tree, ll* arr, ll left, ll right, ll node){
    if(left == right) return tree[node] = arr[left];

    ll mid = (left + right) >> 1;

    ll left_value = init(tree, arr, left, mid, (node << 1) + 1);
    ll right_value = init(tree, arr, mid+1, right, (node << 1) + 2);
    //tree[node] = left_value + right_value;
    //return tree[node];
    return tree[node] = left_value + right_value;
}

//start, end 타겟 인덱스
//left, right 구간합을 구하고자 하는 범위
ll sum(ll* tree, ll start, ll end, ll node, ll left, ll right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];

    ll mid = (start + end) >> 1;

    ll left_value = sum(tree, start, mid, (node << 1) + 1, left, right);
    ll right_value = sum(tree, mid + 1, end, (node << 1) + 2, left, right);

    return left_value + right_value;
}

//index 수정하고자 하는 노드
//diff 수정할 값
void update(ll* tree, ll start, ll end, ll node, ll index, ll diff){
    if(index < start || index > end) return;

    tree[node] += diff;
    if(start == end) return;
    ll mid = (start + end) >> 1;
    update(tree, start, mid, (node << 1)+1, index, diff);
    update(tree, mid+1, end, (node << 1)+2, index, diff);
}

int main(){
    ll tree[4*MAXN] = { 0, };
    ll arr[MAXN] = { 0, };

    ll n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    for(ll i = 0; i < n; i ++) scanf("%lld", arr+i);
    init(tree, arr, 0, n-1, 0);

    for(ll i = 0; i < m+k; i ++){
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        switch(a){
            case 1:
            update(tree, 0, n-1, 0, b-1, c-arr[b-1]);
            break;
            case 2:
            printf("%lld\n", sum(tree, 0, n-1, 0, b-1, c-1));
            break;
        }
    }

    return 0;
}