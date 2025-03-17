#include <cstdio>
#include <algorithm>

constexpr int N = 51;

constexpr int get_left(int x){
	return (x << 1) + 1;
}

constexpr int get_right(int x){
	return (x << 1) + 2;
}

int main(){
	int cnt[N] = { 0, };
	int idx[N*1000*4] = { 0, };

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%d", cnt+i);
	
	int c = 0, l = 0, r = 0;
	
	for(int i = 1; i <= n; i ++){
		if(cnt[i] != 1){
			if(idx[l] == i-1){
				l = get_left(l);
				idx[l] = i;
			}
			if(idx[r] == i-1){
				r = get_right(r);
				idx[r] = i;
			}
			continue;
		}
		if(l != r){
			l = get_left(l);
			idx[l] = i;
		}
		else{
			c = get_left(c);
			l = c;
			r = c;
			idx[c] = i;
		}
	}
	
	int result = std::max({
		idx[l],
		idx[r],
		idx[r] - idx[c] + idx[l] - idx[c]
	});
	
	printf("%d\n", result);

	return 0;
}
