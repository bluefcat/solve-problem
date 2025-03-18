#include <cstdio>
#include <unordered_map>
#include <tuple>

constexpr int N = 601;

char to_char[3] = {'R', 'P', 'S'};
std::unordered_map<char, int> to_num = {
	{'R', 0},
	{'P', 1},
	{'S', 2}
};

std::unordered_map<char, char> beat = {
	{'R', 'P'},
	{'P', 'S'},
	{'S', 'R'}
};


std::tuple<int, int, int> query(char* command){
	int x = 0, y = -1, z = -1;
	printf("%c %s\n", '?', command);
	fflush(stdout);
	
	scanf("%d %d %d", &x, &y, &z);
	return {x, y, z};
}


int main(){
	int n;
	scanf("%d", &n);

	char target[N] = { 0, };
	int need[3] = { 0, };

	char command[N] = { 0, };

	char only[3][N] = { 0, }; 
	for(int i = 0; i < 3; i ++){
		for(int j = 0; j < n; j ++)
			only[i][j] = to_char[i];
	}
	
	for(int i = 0; i < 3; i ++){
		auto [w, d, l] = query(only[i]);
		need[to_num[only[i][0]]] = w;
		if(d != -1) command[d-1] = beat[only[i][0]];
		if(l != -1) command[l-1] = beat[beat[only[i][0]]];
	}

	char tmp[N] = { 0, };
	for(int i = 0; i < 139; i ++){
		for(int j = 0; j < 3; j ++){
			for(int k = 0; k < n; k ++){
				if(command[k] != 0)
					tmp[k] = command[k];
				else
					tmp[k] = to_char[j];
			}

			auto [w, d, l] = query(tmp);
			if(d != -1) command[d-1] = beat[tmp[d-1]];
			if(l != -1) command[l-1] = beat[beat[tmp[l-1]]];
			if(d == -1 && l == -1){
				for(int q = 0; q < n; q++)
					command[q] = tmp[q];
				goto ANSWER;
			}
		}
	}

ANSWER:
	printf("%c %s\n", '!', command);

	return 0;
}
