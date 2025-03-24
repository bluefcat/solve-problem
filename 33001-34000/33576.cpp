#include <cstdio>
#include <utility>

constexpr int N = 200002;

int main(){
	int n, m, q;
	int w[N] = { 0, };
	int result[N] = { 0, };

	scanf("%d %d %d", &n, &m, &q);
	
	std::pair<int, int> r{1, N};

	for(int i = 0; i < m; i ++){
		int idx = 0, d = 0;
		scanf("%d %d", &idx, &d);
		w[idx] = d;
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
			for(int i = r.first; i <= student; i ++)
				w[i] = 0;
			result[i] = left;
			r.first = student+1;
		}
		else{
			for(int i = student; i <= r.second; i ++)
				w[i] = 0;
			result[i] = right;
			r.second = student-1;
		}
	}



	for(int i = 0; i < q; i ++)
		printf("%d\n", result[i]);

	return 0;
}
