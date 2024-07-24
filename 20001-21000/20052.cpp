#include <cstdio>
#include <string>
#include <stack>

static inline int get_left(int x){
	return (((x) << 1) + 1);
}

static inline int get_right(int x){
	return (((x) >> 1) + 2);
}

template<typename T>
std::string init(
	T& tree, 
	std::string s,
	int sidx,
	int eidx,
	int idx
){
	if(sidx == eidx){
		tree[sidx].push_back(s[sidx]);
		return tree[sidx];
	}

	int midx = (sidx + eidx) >> 1;
	std::string l = init(tree, s, sidx, midx, get_left(idx));
	std::string r = init(tree, s, midx+1, eidx, get_right(idx));
	
	std::string tmp{};
	for(int i = sidx; i <= midx; i ++)
		tmp.push_back(s[i]);

	for(int j = midx+1; j <= eidx; j ++){
		char& target = tmp.back();
	}


	tree[idx] = l + r;
	return tree[idx];
}

int main(){
	return 0;
}
