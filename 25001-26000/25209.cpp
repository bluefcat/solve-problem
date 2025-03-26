#include <cstdio>
#include <tuple>
#include <algorithm>
#include <vector>
#include <unordered_map>

constexpr int N = 10;
using std::tuple;
using std::unordered_map;

enum class Block{
	None = 0,
	/* ...
	 * ...
	 * ... 
	 */
	Empty = 1,
	/* ###
	 * ###
	 * ###
	 */
	Full = 2,
	/* ###
	 * #n#
	 * ### 
	 */
	Number = 3,
	/* #..
	 * ##.
	 * ### 
	 */
	RightDown = 4,
	/* ###
	 * ##.
	 * #.. 
	 */
	LeftDown = 5,
	/* ###
	 * .##
	 * ..# 
	 */
	LeftUp = 6,
	/* ..#
	 * .##
	 * ### 
	 */
	RightUp = 7
};

char display[3*N+1][3*N+1];
Block field[N][N];
int n, m;

bool check_diagonal[N][N] = { false, };

Block interpret(int y, int x){
	tuple<int, int> direction[4] = { //counter clockwise (r d l u)
		{2, 1}, {1, 2}, {0, 1}, {1, 0}
	};	
	bool checker[4] = { false, }; // r d l u
	
	for(int i = 0; i < 4; i ++){
		auto [dx, dy] = direction[i];
		checker[i] = display[y+dy][x+dx] == '.';
	}

	if(std::all_of(checker, checker+4, [](bool x){ return x; })){
		return Block::Empty;
	}

	bool r = checker[0], d= checker[1], l = checker[2], u = checker[3];

	
	if(r && d) return Block::LeftDown;
	if(r && u) return Block::RightDown;
	if(l && u) return Block::RightUp;
	if(l && d) return Block::LeftUp;

	if(display[y+1][x+1] != '#') return Block::Number;
	return Block::Full;
}

bool is_boundary(int y, int x){ 
	return (0<= y && y <= n) && (0 <= x && x <= m);
}

auto walk_axis(int y, int x){
	std::vector<tuple<int, int>> result{};

	bool check_axis[N][N] = { false, };
	int py = y, px = x;
	int dy = 1, dx = 0;
	while(check_axis[py][px] == false){
		while(is_boundary(py, px+1) && field[py][px+1] == Block::Empty){
			if(!is_boundary(py+1, px)) break;
			if(
				field[py+1][px] == Block::Empty ||
				field[py+1][px] == Block::LeftDown ||
				field[py+1][px] == Block::RightDown 
			){
				return std::vector<tuple<int, int>>{};
			}
			check_axis[py][px] = true;
			px = px, py = py + 1;
		}	


	}
	return result;
}

auto walk_diagonal(int y, int x){
	std::vector<tuple<int, int>> result{};

	int py = y, px = x;

	while(check_diagonal[py][px] == false){
		check_diagonal[py][px] = true;
		switch(field[py][px]){
			case Block::RightDown:
				if(!is_boundary(py, px+1))
					return std::vector<tuple<int, int>>{};
				
				if(field[py][px+1] == Block::RightUp){
					result.push_back({px+1, py+1});
					px = px+1, py = py;
				}
				else if(
					is_boundary(py+1, px+1) && 
					field[py][px+1] == Block::Empty &&
					field[py+1][px+1] == Block::RightDown
				){
					px = px+1; py = py+1;
				}
				else{
					return std::vector<tuple<int, int>>{};
				}
				break;
			case Block::LeftDown:
				if(!is_boundary(py+1, px))
					return std::vector<tuple<int, int>>{};
				
				if(field[py+1][px] == Block::RightDown){
					result.push_back({px, py+1});
					px = px, py = py+1;
				}
				else if(
					is_boundary(py+1, px-1) && 
					field[py+1][px] == Block::Empty &&
					field[py+1][px-1] == Block::LeftDown
				){
					px = px-1; py = py+1;
				}
				else{
					return std::vector<tuple<int, int>>{};
				}
				break;
			case Block::LeftUp:
				if(!is_boundary(py, px-1))
					return std::vector<tuple<int, int>>{};
				
				if(field[py][px-1] == Block::LeftDown){
					result.push_back({px, py});
					px = px-1, py = py;
				}
				else if(
					is_boundary(py-1, px-1) && 
					field[py][px-1] == Block::Empty &&
					field[py-1][px-1] == Block::LeftUp
				){
					px = px-1; py = py-1;
				}
				else{
					return std::vector<tuple<int, int>>{};
				}
				break;
			case Block::RightUp:
				if(!is_boundary(py-1, px))
					return std::vector<tuple<int, int>>{};
				
				if(field[py-1][px] == Block::LeftUp){
					result.push_back({px+1, py});
					px = px, py = py-1;
				}
				else if(
					is_boundary(py-1, px+1) && 
					field[py-1][px] == Block::Empty &&
					field[py-1][px+1] == Block::RightUp
				){
					px = px+1; py = py-1;
				}
				else{
					return std::vector<tuple<int, int>>{};
				}
				break;

			default:
				return std::vector<tuple<int, int>>{};
		}
	}

	return result;
}

int main(){
	scanf("%d %d", &n, &m);

	for(int y = 0; y < 3*n; y ++){
		scanf("%s", display[y]);
	}

	for(int y = 0; y < 3*n; y += 3){
		for(int x = 0; x < 3*m; x += 3){
			field[y/3][x/3] = interpret(y, x);
		}
	}

	for(int y = 0; y < n; y ++){
		for(int x = 0; x < n; x ++){
			if(check_diagonal[y][x]) continue;
			if(
				field[y][x] == Block::Empty || 
				field[y][x] == Block::Number ||
				field[y][x] == Block::Full
			) continue;

			if(walk_diagonal(y, x).size() != 4){
				printf("NO\n");
				return 0;
			}

			for(auto [x, y]: walk_diagonal(y, x)){
				printf("(%d %d) ", x, y);
			}
			printf("\n");
		}
	}
	
	printf("YES\n");
	return 0;
}
