#include <cstdio>
#include <utility>
#include <algorithm>

constexpr int N = 100001;

int main(){
	int n, m, q;
	int w[N] = { 0, };
	int result[N] = { 0, };

	scanf("%d %d %d", &n, &m, &q);
	
	std::pair<int, int> r{N+1, -1};

	for(int i = 0; i < m; i ++){
		int idx = 0, d = 0;
		scanf("%d %d", &idx, &d);
		w[idx] = d;
		r.first = std::min(r.first, idx);
		r.second = std::max(r.second, idx);
	}
	
	for(int i = 0; i < q; i ++){
		int student = 0;
		scanf("%d", &student);
		
		if(student < r.first || r.second < student){
			result[i] = 0;
			continue;
		}
		
		int left = 0, right = 0;
		for(int i = r.first; i <= student; i ++)
			left += w[i];

		for(int i = student; i <= r.second; i ++)
			right += w[i];

		if(left <= right){
			result[i] = left;
			r.first = student+1;
		}
		else{
			result[i] = right;
			r.second = student-1;
		}
	}



	for(int i = 0; i < q; i ++)
		printf("%d\n", result[i]);

	return 0;
}
