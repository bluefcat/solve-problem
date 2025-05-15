#include <cstdio>
#include <string>

using lint = long long;
lint mpow(lint x, lint e){
	lint result = 1;
	while(e){
		if(e & 1) result *= x;
		x *= x;
		e >>= 1;
	}
	return result;
}

bool check(lint pos, lint n){
	lint result = 10;
	lint tmp = 110;
	for(int i = 2; i <= n; i ++){
		result += i*tmp;
		tmp *= 10;
	}
	return pos < result;
}

int main(){
	while(true){
		int n, k;
		scanf("%d %d", &n, &k);
		if(n == 0 && k == 0) return 0;


		lint no = 0, yes = 100;

		while(no + 1 < yes){
			lint mid = (yes + no) >> 1;
			if(check(n, mid)) yes = mid;
			else no = mid;
		}

		lint cnt = yes==1?0:10;
		lint tmp = 110;
		for(int i = 2; i < yes; i ++){
			cnt += i*tmp; tmp *= 10;
		}
		lint idx = (yes==1?0:mpow(10, yes-1)) + (n-cnt)/yes;
		lint offset = (n-cnt) % yes;
		std::string buffer = std::to_string(idx);
		int i =0;
		for(i = offset; i < buffer.size(); i ++){
			printf("%c", buffer[i]);
			k--;
			if( k == 0) break;
		}

		while(k != 0){
			for(; i < buffer.size(); i++){
				printf("%c", buffer[i]);
				k --;
				if(k ==0) break;
			}
			i = 0;
			idx++;
			buffer = std::to_string(idx);
		}
		printf("\n");	
	}
	return 0;
}
