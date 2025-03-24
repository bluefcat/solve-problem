#include <cstdio>
#include <utility>
#include <unordered_map>

using lint = long long;
constexpr int N = 200002;

int main(){
	int n, m, q;
	lint w[N] = { 0, };
	lint result[N] = { 0, };

	scanf("%d %d %d", &n, &m, &q);
	
	std::pair<int, int> r{1, n};

	for(int i = 0; i < m; i ++){
		int idx = 0; lint d = 0;
		scanf("%d %lld", &idx, &d);
		w[idx] = d;
	}

	for(int i = 1; i <= n; i ++)
		w[i] += w[i-1];
	
	for(int i = 0; i < q; i ++){
		int student = 0;
		scanf("%d", &student);
		
		if(student < r.first || r.second < student){
			result[i] = 0;
			continue;
		}
		
		lint left = w[student] - w[r.first-1];
		lint right = w[r.second] - w[student];
		
		if(left <= right){
			result[i] = left;
			r.first = student;
		}
		else{
			result[i] = right;
			r.second = student;
		}
	}


	for(int i = 0; i < q; i ++)
		printf("%lld\n", result[i]);

	return 0;
}
