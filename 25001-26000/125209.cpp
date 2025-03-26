#include <cstdio>
#include <tuple>
#include <algorithm>
#include <vector>

constexpr int N = 12;
using std::tuple;
using std::vector;

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

struct Vertex{
	tuple<int, int> pos;
	tuple<int, int> l;
	tuple<int, int> r;
};

char display[3*N+1][3*N+1];
Block field[N][N];

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


vector<Vertex> get_vertex(int n, int m){
	vector<Vertex> result{};

	for(int y = 0; y < n; y ++){
		for(int x = 0; x < n+1; x ++){
			Block& a = field[y][x];
			Block& b = field[y+1][x];

			if(a == Block::LeftDown && b == Block::RightDown){
				result.push_back({{x+1, y}, {-1, 1}, {1, 1}});
			}
			else if(a == Block::RightUp && b == Block::LeftUp){
				result.push_back({{x+1, y+1}, {1, 1}, {-1, -1}});
			}
			else if(a == Block::Full && b == Block::RightUp){
				return {};
			}
			else if(a == Block::Full && b == Block::RightDown){
				return {};
			}
			else if(a == Block::LeftDown && b == Block::Full){
				return {};
			}
			else if(a == Block::LeftUp && b == Block::Full){
				return {};
			}
		}
	}

	for(int y = 0; y < n+1; y ++){
		for(int x = 0; x < m; x ++){
			Block& a = field[y][x];
			Block& b = field[y][x+1];

			if(a == Block::LeftDown && b == Block::LeftUp){
				result.push_back({{x+1, y}, {-1, 1}, {-1, -1}});
			}
			else if(a == Block::RightDown && b == Block::RightUp){
				result.push_back({{x+1, y+1}, {1, 1}, {1, -1}});
			}
			else if(a == Block::Full && b == Block::LeftUp){
				return {};
			}
			else if(a == Block::Full && b == Block::RightUp){
				return {};
			}
			else if(a == Block::LeftDown && b == Block::Full){
				return {};
			}
			else if(a == Block::RightDown && b == Block::Full){
				return {};
			}
		}
	}

	return result;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	

	for(int y = 0; y < 3*N; y ++)
		for(int x = 0; x < 3*N; x ++)
			display[y][x] = '#';

	for(int y = 3; y < 3*n; y ++){
		scanf("%s", display[y]+3);
	}

	for(int y = 0; y < n+2; y ++){
		for(int x = 0; x < m+2; x ++){
			field[y][x] = interpret(y*3, x*3);
		}
	}

	for(int y = 0; y < n+2; y ++){
		for(int x = 0; x < m+2; x ++) printf("%d", (int)field[y][x]);
		printf("\n");
	}

	
	printf("YES\n");
	return 0;
}
