#include <cstdio>
#include <algorithm>

constexpr int N = 51;
int left_id = 1, right_id = 2;

int get_left(int x){
	left_id ++;
	while(left_id == right_id) left_id ++;
	return left_id;
}

int get_right(int x){
	right_id ++;
	while(left_id == right_id) right_id ++;
	return right_id;
}

int main(){
	int cnt[N] = { 0, };
	int idx[N*10000*4] = { 0, };

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		scanf("%d", cnt+i);
	
	int  l = 0, r = 0;
	
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
			if(idx[l] == i-1){
				l = get_left(l);
				idx[l] = i;
			}
			else{
				r = get_right(r);
				idx[r] = i;
			}
		}
		else{
			l = 0;
			r = 0;
			idx[0] = i;
		}
	}
	
	int result = std::max({
		idx[l],
		idx[r],
		idx[r] - idx[0] + idx[l] - idx[0]
	});
	
	printf("%d\n", result);

	return 0;
}
