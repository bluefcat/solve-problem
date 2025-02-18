#include <cstdio>
#include <queue>

constexpr int N = 10*10000;

struct Node{
	char character;
	bool terminal;
	Node* next[10] = { nullptr, };
};

Node nodes[N] = {};
int idx = 0;

void print(Node& root, int level = 0){
	for(int i = 0; i < 10; i ++){
		if(root.next[i] == nullptr) return;
		printf("[%d, [p:'%c'], '%c' %d]\n", level, root.character, root.next[i]->character, root.next[i]->terminal);
		print(*root.next[i], level + 1);
	}

}

bool check(Node& root){
	bool result = true;
	if(root.terminal == true && root.next[0] != nullptr) return false;
	for(int i = 0; i < 10; i ++){
		if(root.next[i] == nullptr) break;
		result &= check(*root.next[i]);
	}

	return result;
}


int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		idx = 0;
		for(int i = 0; i < N; i ++)
			for(int j = 0; j < 10; j ++){
				nodes[i].next[j] = nullptr;
				nodes[i].terminal = false;
			}

		int n; 
		scanf("%d", &n);
		for(int i = 0; i < n; i ++){
			char number[11] = { 0, };
			scanf("%s", number);
			
			char* np = number;
			Node* r = nodes + 0; 
			while(*np){
				int j = 0;
				for(j = 0; j < 10; j ++){
					if(r->next[j] == nullptr){
						idx ++;
						r->next[j] = &nodes[idx];
						nodes[idx].character = *np;		
						r = r->next[j];
						break;
					}
					else if(r->next[j]->character == *np){
						r = r->next[j];
						break;
					}
				}		
				np ++;
			}
			r->terminal = true;
		}

		printf("%s\n", check(nodes[0])?"YES":"NO");

	}
	return 0;
}
