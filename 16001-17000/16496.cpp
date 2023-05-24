#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

bool compare(std::string x, std::string y){
	if((x+y) > (y+x)) return true;
	return false;
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	bool all_zero = true;
	int n;
	std::vector<std::string> numbers;

	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		char tmp[11] = { 0, };
		scanf("%s", tmp);

		numbers.push_back(tmp);
		if(strcmp("0", tmp) != 0) all_zero = false; 
	}
	
	if(all_zero){
		printf("0\n");
		return 0;
	}

	std::sort(numbers.begin(), numbers.end(), compare);
	
	for(auto& x: numbers) printf("%s", x.c_str());
	printf("\n");

	return 0;
}
