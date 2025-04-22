#include <cstdio>
#include <vector>
#include <climits>
#include <tuple>
#include <cassert>

struct node{
	int row;
	int size;
	node* col;

	node *up, *down, *left, *right;
};

void dlx_cover(node* head){
	//delete head node
	/*
	 * [l | A | r] <-> [l | head | r] <-> [l | B | r]
	 * [l | A | r] <--------------------> [l | B | r]
	 */
	head->right->left = head->left;
	head->left->right = head->right;
	
	//circular linked list
	for(node* it = head->down; it != head; it = it->down){
		for(node* jt = it->right; jt != it; jt = jt->right){
			jt->down->up = jt->up;
			jt->up->down = jt->down;
			jt->col->size --;
		}
	}
}

void dlx_uncover(node* head){
	for(node* it = head->up; it != head; it = it->up){
		for(node* jt = it->left; jt != it; jt = jt->left){
			jt->down->up = jt;
			jt->up->down = jt;
			jt->col->size ++;
		}
	}
	
	head->left->right = head;
	head->right->left = head;
}

bool dlx_search(node* head, int k, std::vector<int>& solution){
	if(head->right == head) return true;

	node* ptr = nullptr;
	int low = INT_MAX;
	
	for(node* it = head->right; it != head; it = it->right){
		if(it->size < low){
			if(it->size == 0) return false;
			low = it->size;
			ptr = it;
		}
	}

	dlx_cover(ptr);
	
	for(node* it = ptr->down; it != ptr; it = it->down){
		solution.push_back(it->row);
		for(node* jt = it->right; jt != it; jt = jt->right){
			dlx_cover(jt->col);
		}

		if(dlx_search(head, k+1, solution)) return true;

		solution.pop_back();
		for(node* jt = it->left; jt != it; jt = jt->left){
			dlx_uncover(jt->col);
		}
	}
	dlx_uncover(ptr);
	return false;
}

constexpr int get_idx(int x, int r, int c){
	return (x*10*10)+(r*10)+c;
}
constexpr int get_cell(int r, int c){
	return ((r-1)/3) * 3 + ((c-1)/3) + 1;
}

constexpr std::tuple<int, int, int> get_value(int idx){
	return {(idx / 100) % 10, (idx / 10) % 10, idx % 10};
}

node* board_[1000+1];

template<typename T>
node* append(T row, T head){
	node* result = new node{row};
	result->left = result;
	result->right = result;

	node* h = board_[head];
	h->size ++;
	node* it = h;
	for(;it->down != h; it = it->down);
	
	result->up = it; 
	it->down = result;
	result->down = h; 
	h->up = result;
	result->col = h;

	return result;
}

template<typename T, typename... Args>
node* append(T row, T head, Args... args){
	node* result = append(row, head);
	node* next = append(args...);
	
	result->right = next; 
	result->left = next->left;
	next->left = result;
	result->left->right = result;
	//next->right = result;
	return result;
}



int main(){
	std::vector<int> solution{};
	node* head = new node{0, 0};
	head->up = head; head->down = head; head->left = head; head->right = head;
	
	node* cur = head;

	for(int t = 0; t < 4; t ++){
		for(int i = 1; i <= 9; i ++){
			for(int j = 1; j <= 9; j ++){
				node* h = new node{0, 0};
				h->up = h; h->down = h;
				h->left = cur; h->right = cur->right;
				cur->right = h;
				board_[get_idx(t, i, j)] = h;
				cur = h;
			}
		}
	}

	int board[9][9] = { 0, };
	for(int i = 1; i <= 9; i ++){
		for(int j = 1; j <= 9; j ++){
			int l = 0, r = 0;
			scanf("%d", &l);
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

				board[i-1][j-1] = tmp;
			}
		}
	}
		

	//
	bool result = dlx_search(head, 0, solution);

	for(auto& x: solution){
		auto [a, b, c] = get_value(x);
		board[a-1][b-1] = c;
	}

	for(int i = 0; i < 9; i ++){
		for(int j = 0; j < 9; j ++) printf("%d ", board[i][j]);
		printf("\n");
	}


	return 0;
}
