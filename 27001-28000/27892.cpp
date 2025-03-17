#include <cstdio>
#include <unordered_set>
#include <unordered_map>

using lint = long long;
using std::unordered_set;
using std::unordered_map;

lint f(lint x){
	if(x & 1){
		return (x << 1) ^ 6;
	}
	return (x >> 1) ^ 6;
}

int main(){
	lint x, N;
	unordered_set<lint> tail{};
	unordered_map<lint, lint> tmap{};
	unordered_set<lint> head{};
	unordered_map<lint, lint> hmap{};

	scanf("%lld %lld", &x, &N);
	
	lint turtle = x;
	lint rabbit = x;

	do{
		turtle = f(turtle);
		rabbit = f(f(rabbit));
	}while(turtle != rabbit);
	
	lint init = turtle;
	
	do{
		head.insert(turtle);
		turtle = f(turtle);
	}while(init != turtle);

	lint t = x;
	int idx = 0;
	while(head.find(t) == head.end()){
		tail.insert(t);
		tmap[idx] = t; idx++;
		t = f(t);
	}

	idx = 0;
	lint q = t;
	do{
		hmap[idx] = q; idx++;
		q = f(q);
	}while(q != t);

	if(N < tail.size()){
		printf("%lld\n", tmap[N]);
		return 0;
	}

	printf("%lld\n", hmap[N % head.size()]);
	return 0;
}
