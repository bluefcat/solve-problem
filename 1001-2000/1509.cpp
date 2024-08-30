#include <cstdio>
#include <string>

using std::string;
constexpr int N = 2502;
bool is_palindrome[N][N] = { false, };

bool is_pald(string& str, int l = 0, int r = 0){
	while(l <= r){
		if(str.at(l) != str.at(r)) return false;
		l ++;
		r --;
	}
	return true;
}

int main(){


	int cache[N] = { 0, };
	char tmp[N] = { 0, };
	scanf("%s", tmp);
	string str{tmp};
	
	//odd;
	for(int p = 0; p < str.size(); p ++){
		int l = p-1, r = p+1;
		is_palindrome[p][p] = true;
		while(0 <= l && r < str.size()){
			is_palindrome[l][r] = (str.at(l) == str.at(r)) && is_palindrome[l+1][r-1];
			l --;
			r ++;
		}	
	}
	//even
	for(int p = 0, q = 1; q < str.size(); p ++, q ++){
		int l = p-1, r = q+1;
		is_palindrome[p][q] = (str.at(p) == str.at(q));
		while(0 <= l && r < str.size()){
			is_palindrome[l][r] = (str.at(l) == str.at(r)) && is_palindrome[l+1][r-1];
			l --;
			r ++;

		}
	}

	cache[0] = 1;
	
	for(int i = 1; i < str.size(); i ++){
		cache[i] = i+1;
		if(is_palindrome[0][i]) cache[i] = 1;
		for(int j = i-1; j >= 0; j --){
			if(is_palindrome[j+1][i]){
				cache[i] = std::min(cache[i], cache[j]+1);
			}
		}
	}
	printf("%d\n", cache[str.size()-1]);

	return 0;
}
