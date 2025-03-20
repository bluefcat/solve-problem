#include <cstdio>
#include <vector>

int main(){
	std::vector<int> result{};
	int n;
	scanf("%d", &n);

	int cur = 1;
	result.push_back(cur);
	if((n-2) % 3 == 0){
		cur = 2;
		result.push_back(cur);
	}
	while(true){
		if(cur + 2 == n){
			result.push_back(cur + 2);
			result.push_back(cur + 1);
			result.push_back(1);
			break;
		}
		else if(cur == n){
			result.push_back(1);
			break;
		}
		result.push_back(cur + 2); //move clock two
		result.push_back(cur + 1); //move counter one
		result.push_back(cur + 3); //move clock two
		
		cur += 3;
	}

	printf("%ld\n", result.size()-1);
	
	for(auto& x: result){
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}
