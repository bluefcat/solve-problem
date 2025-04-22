#include <cstdio>
#include <vector>
#include <climits>
#include <tuple>
#include <cassert>

struct Node{
	int row;
	int size;
	Node* col{nullptr};
	Node *up{this}, *down{this}, *left{this}, *right{this};	
};

void dlx_cover(Node* head){
	//delete head Node
	/*
	 * [l | A | r] <-> [l | head | r] <-> [l | B | r]
	 * [l | A | r] <--------------------> [l | B | r]
	 */
	head->right->left = head->left;
	head->left->right = head->right;
	
	//circular linked list
	for(Node* it = head->down; it != head; it = it->down){
		for(Node* jt = it->right; jt != it; jt = jt->right){
			jt->down->up = jt->up;
			jt->up->down = jt->down;
			jt->col->size --;
		}
	}
}

void dlx_uncover(Node* head){
	for(Node* it = head->up; it != head; it = it->up){
		for(Node* jt = it->left; jt != it; jt = jt->left){
			jt->down->up = jt;
			jt->up->down = jt;
			jt->col->size ++;
		}
	}
	
	head->left->right = head;
	head->right->left = head;
}

bool dlx_search(Node* head, int k, std::vector<int>& solution){
	if(head->right == head) return true;

	Node* ptr = nullptr;
	int low = INT_MAX;
	
	for(Node* it = head->right; it != head; it = it->right){
		if(it->size < low){
			if(it->size == 0) return false;
			low = it->size;
			ptr = it;
		}
	}

	dlx_cover(ptr);
	
	for(Node* it = ptr->down; it != ptr; it = it->down){
		solution.push_back(it->row);
		for(Node* jt = it->right; jt != it; jt = jt->right){
			dlx_cover(jt->col);
		}

		if(dlx_search(head, k+1, solution)) return true;

		solution.pop_back();
		for(Node* jt = it->left; jt != it; jt = jt->left){
			dlx_uncover(jt->col);
		}
	}
	dlx_uncover(ptr);
	return false;
}


Node* board_[500+1];

constexpr int get_idx(int x, int r, int c){
	return (x*10*10)+(r*10)+c;
}
constexpr int get_cell(int r, int c){
	return ((r-1)/3) * 3 + ((c-1)/3) + 1;
}

constexpr std::tuple<int, int, int> get_value(int idx){
	return {(idx / 100) % 10, (idx / 10) % 10, idx % 10};
}

void init(Node* head){
	Node* cur = head;
	for(int t = 0; t < 4; t ++){
		for(int i = 1; i <= 9; i ++){
			for(int j = 1; j <= 9; j ++){
				Node* h = new Node{0, 0};
				h->up = h; h->down = h;
				h->left = cur; h->right = cur->right;
				cur->right = h;
				board_[get_idx(t, i, j)] = h;
				cur = h;
			}
		}
	}
}

template<typename T>
Node* append(T row, T head){
	Node* result = new Node{row};
	Node* h = board_[head];

	h->size ++;
	Node* it = h;
	for(;it->down != h; it = it->down);
	
	result->up = it; 
	it->down = result;
	result->down = h; 
	h->up = result;
	result->col = h;

	return result;
}

template<typename T, typename... Args>
Node* append(T row, T head, Args... args){
	Node* result = append(row, head);
	Node* next = append(args...);
	
	result->right = next; 
	result->left = next->left;

	next->left->right = result;
	next->left = result;
	return result;
}



int main(){
	int answer = -1;
	int board[9][9] = { 0, };
	for(int t = 0; t < 81; t ++){
		int s, u, v;
		scanf("%d %d %d", &s, &u, &v);
		board[s-1][u-1] = v;

		std::vector<int> solution{};
		Node* head = new Node{0, 0};
		
		init(head);

		for(int i = 1; i <= 9; i ++){
			for(int j = 1; j <= 9; j ++){
				int l = board[i-1][j-1], r = 0;
				r = l + 1;
				if(l == 0){
					l = 1; r = 10;
				}
				
				for(int tmp = l; tmp < r; tmp ++){
					int row = get_idx(i, j, tmp);
					int h0 = get_idx(0, i, j);
					int h1 = get_idx(1, i, tmp);
					int h2 = get_idx(2, j, tmp);
					int h3 = get_idx(3, get_cell(i, j), tmp);
					append(
						row, h0, row, h1, row, h2, row, h3
					);
				}
			}
		}
			
		bool result = dlx_search(head, 0, solution);
		if(!result && answer == -1){
			answer = t+1;
		}
		for(int i = 0; i < 501; i ++){
			if(board_[i] != nullptr){
				Node* it = board_[i]->down;
				for(; it != board_[i]; it = it->down){
					if(it->up == board_[i]) continue;
					delete it->up;
				}
				delete board_[i];
			}
		}
		delete head;
	}

	printf("%d\n", answer);
	return 0;
}
