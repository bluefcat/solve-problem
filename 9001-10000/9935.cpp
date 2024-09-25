#include <stack>
#include <string>
#include <utility>

constexpr int N = 1000001;

using std::stack;
using std::string;
using pair = std::pair<char, int>;

int main(){
	char tmp[N] = { 0, };	
	scanf("%s", tmp);
	string target(tmp);
	scanf("%s", tmp);
	string bomb(tmp);
	
	stack<pair> s{};
	int cur = 0;
	
	for(char& w: target){
		if(cur == bomb.size()){
			while(cur--) s.pop();
			if(!s.empty())
				cur = s.top().second;
		}

		if(w == bomb[cur])
			cur ++;
		else if(w == bomb[0])
			cur = 1;
		else
			cur = 0;

		s.push({w, cur});
	}
	if(cur == bomb.size()){
		while(cur--) s.pop();
		if(!s.empty())
			cur = s.top().second;
	}

	if(s.empty()){
		printf("FRULA\n");
		return 0;
	}

	stack<char> result{};
	while(!s.empty()){
		result.push(s.top().first);
		s.pop();
	}

	while(!result.empty()){
		printf("%c", result.top());
		result.pop();
	}
	printf("\n");
	return 0;
}
