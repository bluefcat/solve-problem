#include <cstdio>

constexpr int N = 13000000+1;


struct Idx{
	constexpr int operator()(char x){
		return (int)(x - 'a');
	}
};


template<unsigned int T, typename Type, typename F>
struct Node{
	bool term = false;
	Node* next[T] = { nullptr };	

	Node(){}
	~Node(){
		for(int i = 0; i < T; i ++)
			if(next[i]) delete next[i];
	}

	void insert(Type* element){
		Node* cur = this;
		while(*element){
			int key = F()(*element);
			if(!cur->next[key])
				cur->next[key] = new Node<T, Type, F>{};
			
			cur = cur->next[key];
			element ++;
		}
		cur->term = true;
	}

	bool check(Type* element){
		Node* cur = this; 
		while(*element){
			int key = F()(*element);
			if(!cur->next[key]) return false;
			cur = cur->next[key];
			element ++;
		}
		return cur->term;
	}
};


int main(){
	Node<26, char, Idx> node{};

	int n, m, result = 0;
	scanf("%d %d", &n, &m);

	while(n--){
		char tmp[501] = { 0, };
		scanf("%s", tmp);
		node.insert(tmp);
	}

	while(m--){
		char tmp[501] = { 0, };
		scanf("%s", tmp);
		result += (int)node.check(tmp);
	}
	printf("%d\n", result);

	return 0;
}
