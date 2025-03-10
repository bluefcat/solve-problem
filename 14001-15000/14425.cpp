#include <cstdio>

constexpr int N = 26 * 500 + 1;

constexpr int get_idx(char x){
	return (int)(x - 'a');
}

struct Node{
	bool term = false;
	Node* next[26] = { nullptr };	
};

Node nodes[N];
int size = 0;

int main(){
	Node* root = nodes + 0;

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
				cur->next[idx] = nodes + (++size);
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
		while(*p && cur){
			cur = cur->next[get_idx(*p)];	
			p ++;
		}

		result += (int)(cur != nullptr && cur->term);
	}
	printf("%d\n", result);

	return 0;
}
