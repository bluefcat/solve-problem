#include <cstdio>
#include <queue>

struct Node{
	int id = -1;
	int depth = 0;
	Node *left{nullptr}, *right{nullptr};
};

int arr[300002];
int size = 0;

Node tree[300002];


void predict_node(Node* head, int& count){
	if(head->left)
		predict_node(head->left, count);
	arr[head->id] = count;
	count ++;
	if(head->right)
		predict_node(head->right, count);
}


int main(){
	tree[0].id = 0; //head;
	size++;

	int n;
	scanf("%d", &n);
	std::queue<Node*> q({tree+0});


	for(int i = 1; i < n; i ++){
		int depth;
		scanf("%d", &depth);
		std::queue<Node*> tmp{};
		int de = -1;
		while(!q.empty() && de != depth){
			Node* cur = q.front(); q.pop();
			if(cur->left == nullptr && cur->depth + 1 == depth){
				cur->left = tree+size;
				tree[size].id = size;
				tree[size].depth = cur->depth + 1;
				de = tree[size].depth;
				size ++;

				tmp.push(cur->left);
			}
			else if(cur->right ==nullptr && cur->depth+1 ==depth){
				cur->right = tree+size;
				tree[size].id = size;
				tree[size].depth = cur->depth + 1;
				de = tree[size].depth;
				size ++;
				tmp.push(cur->right);
			}

			if(!(cur->left && cur->right))
				tmp.push(cur);
		}

		while(!tmp.empty()){
			q.push(tmp.front()); tmp.pop();
		}
	}
	int count = 1;
	predict_node(tree+0, count);
	
	for(int i = 0; i < n; i ++){
		if(arr[i] == 0){
			printf("-1\n");
			return 0;
		}
	}


	for(int i = 0; i < n; i ++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
