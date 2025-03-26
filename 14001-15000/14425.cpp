#include <cstdio>

constexpr int N = 13000000+1;

constexpr int get_idx(char x){
	return (int)(x - 'a');
}

struct Node{
	bool term = false;
	Node* next[26] = { nullptr };	
};

Node nodes;

int main(){
	Node* root = &nodes;

	int n, m, result = 0;
	scanf("%d %d", &n, &m);

	while(n--){
		char tmp[501] = { 0, };
		scanf("%s", tmp);
		
		Node* cur = root;

		char* p = tmp;
		while(*p){
			int idx = get_idx(*p);
			if(cur->next[idx] == nullptr)
				cur->next[idx] = new Node();
			cur = cur->next[get_idx(*p)];
			p ++;
		}
		cur->term = true;
	}

	while(m--){
		char tmp[501] = { 0, };
		scanf("%s", tmp);

		Node* cur = root;
		char* p = tmp;
		while(cur && *p){
			cur = cur->next[get_idx(*p)];	
			p ++;
		}

		result += (int)(cur != nullptr && cur->term);
	}
	printf("%d\n", result);

	return 0;
}
