#include <cstdio>
#include <unordered_set>
#include <queue>

using lint = unsigned long long;
using std::unordered_set;
using priority_queue = std::priority_queue<lint>;
constexpr int M = 2000003;

int main(){
	std::unordered_set<lint> prime{};
	priority_queue q{};
	int n = 0;
	scanf("%d", &n);

	lint t = n;
	lint p = 1;
	lint next = 2;
	while(t){
		for(auto& checker: prime){
			if((next % checker) == 0) goto NEXT;
		}
		q.push(next);
		prime.insert(next);
		p *= next;
		t -= 1;
		printf("%lld * ", next);
		NEXT:
		next ++;
	}
	printf("\n");
	printf("%lld\n", p);

	
	return 0;
}
