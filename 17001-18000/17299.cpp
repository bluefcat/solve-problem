#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::stack;

constexpr int N = 1000001;

int main(){
	vector<int> result{};

	vector<int> arr(N, 0);
	vector<int> counter(N, 0);
	stack<int> s{};


	int n;
	scanf("%d", &n);
	int c = 1, cnt = 0;
	for(int i = 0; i < n; i ++){
		scanf("%d", &*(arr.begin()+i));
		counter[arr[i]] ++;
	}
	
	result.push_back(-1);
	s.push(arr[n-1]);

	for(int i = n-2; i >= 0; i --){
		while(!s.empty() && counter[s.top()] <= counter[arr[i]])
			s.pop();
		if(s.empty())
			result.push_back(-1);
		else 
			result.push_back(s.top());
		s.push(arr[i]);
	}

	std::reverse(result.begin(), result.end());
	for(auto x: result)
		printf("%d ", x);
	printf("\n");

	return 0;
}
