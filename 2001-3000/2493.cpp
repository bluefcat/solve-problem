#include <cstdio>
#include <stack>
#include <algorithm>
#include <utility>

using lint = long long;
constexpr int N = 500'001;

lint arr[N] = { 0, };
lint result[N] = { 0, };

int main(){
	std::stack<std::pair<lint, lint>> s{};
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%lld", arr+i);

	std::reverse(arr+0, arr+n);
	
	s.push({0, arr[0]});
	for(int i = 1; i < n; i ++){
		while(!s.empty() && s.top().second <= arr[i]){
			result[s.top().first] = n-i;
			s.pop();
		}
		s.push({i, arr[i]});
	}
	
	for(int i = n-1; i >= 0; i --)
		printf("%lld ", result[i]);
	printf("\n");

	return 0;
}
