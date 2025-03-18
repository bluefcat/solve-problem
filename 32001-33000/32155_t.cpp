#include <cstdio>
#include <unordered_map>
#include <tuple>

#include <ctime>
#include <cstdlib>
#include <cstring>

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

char tester[N] = { 0, };

std::tuple<int, int, int> query(char* command){
	int x = 0, y = -1, z = -1;
	//printf("%c %s\n", '?', command);
	//fflush(stdout);
	
	for(int i = 0; *(command+i); i ++){
		x += (beat[tester[i]] == command[i]);
		if(y == -1 && command[i] == tester[i])
			y = i+1;
		if(z == -1 && beat[command[i]] == tester[i])
			z = i+1;
	}

	//scanf("%d %d %d", &x, &y, &z);
	return {x, y, z};
}


int main(){
	srand((unsigned int)time(NULL));
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i ++) tester[i] = to_char[rand()%3];
	
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
	for(int i = 0; i < 130; i ++){
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
		}
	}
	printf("> %s\n", tester);
	printf("%c %s\n", '!', command);
	
	bool flag = true;
	for(int i = 0; *(command + i); i ++){
		flag &= (beat[tester[i]] == command[i]);
	}

	printf("%ld\n", strlen(command));

	printf("%d\n", flag);

	return 0;
}
