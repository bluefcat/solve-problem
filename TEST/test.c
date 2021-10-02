#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MODE 0644
#define STDOUT 100

int mprintf(const char* string, ...);
int msystem(const char* string, ...);

int get_path(int fd, const char* codedir, const char* codename, char* target_path, char* solve_path);

int make_data(const char* data_fname, int* ranges, int length);
int run_code(const char* code_path, const char* data_fname, const char* result);

int compare_result(const char* target, const char* answer);

int main(int argc, char* argv[]){
	if(argc < 2){
		printf("USAGE: %s <test file name> [value's ranges...]\n", argv[0]);
		return 1;
	}
	
	srand((unsigned int)time(NULL));

	int output = open("out", O_RDWR | O_CREAT | O_TRUNC, MODE);
	dup2(1, STDOUT);
	close(1);
	dup2(output, 1);

	//argv[0] is named this file's compile
	//argv[1] is test file name
	const char* target_fname = argv[1];

	//data ranges
	int* ranges = (int*)malloc(sizeof(int) * argc - 2);
	for(int i = 2; i < argc; i ++) ranges[i-2] = atoi(argv[i]);
	

	char target_path[1024] = { 0, };
	char answer_path[1024] = { 0, };
	get_path(output, "../", target_fname, target_path, answer_path);


	const char* target_result_name = "trn";
	const char* answer_result_name = "arn";

	const char* data = "data";

	make_data(data, ranges, (argc-2) >> 1);	
	run_code(target_path, data, target_result_name);
	run_code(answer_path, data, answer_result_name);

	int answer = compare_result(target_result_name, answer_result_name);

	if(answer == 0){
		mprintf("Correct!\n");
	}
	else{
		mprintf("Failed!\n");
	}
	
	//end
	close(output);
	free(ranges);
	
	msystem("rm data out trn arn");

	return 0;
}

int mprintf(const char* string, ...){
	char result[1024] = { 0, };

	va_list ap;
	va_start(ap, string);

	vsprintf(result, string, ap);
	
	write(STDOUT, result, strlen(result)+1);

	va_end(ap);
	return 0;
}

int msystem(const char* string, ...){
	char result[1024] = { 0, };

	va_list ap;
	va_start(ap, string);

	vsprintf(result, string, ap);
	va_end(ap);

	return system(result);
}

int get_path(int fd, const char* codedir, const char* codename, char* target_path, char* solve_path){
	char tmp[1024] = { 0, };

	msystem("find %s -name %s", codedir, codename);

	lseek(fd, 0, SEEK_SET);
	read(fd, tmp, 1024);

	char* p = strtok(tmp, "\n");

	for(int i = 0; i < 2; i ++){
		if(strstr(p, "TEST")) strcpy(target_path, p);
		else strcpy(solve_path, p);

		p = strtok(NULL, "\n");
	}

	return 0;
}

int make_data(const char* data_fname, int* ranges, int length){
	if(length < 1) return 0;

	int data_fd = open(data_fname, O_RDWR | O_CREAT | O_TRUNC, MODE);
	
	for(int i = 0; i < 10; i ++){
		char tmp[1024] = { 0, };

		int min_idx = 0, max_idx = 1;
		
		for(int n = 0; n < length; n ++){
			char number[1024] = { 0, };
			int x = rand() % ((ranges[max_idx] - ranges[min_idx]) + 1) + ranges[min_idx];

			min_idx += 2;
			max_idx += 2;
			
			sprintf(number, "%d ", x);
			strcat(tmp, number);
		}
		write(data_fd, tmp, strlen(tmp));
		write(data_fd, "\n", strlen("\n"));
	}

	close(data_fd);
	return 0;
}

int run_code(const char* code_path, const char* data_fname, const char* result){
	char out_fname[1024] = { 0, };
	char result_fname[1024] = { 0, };

	//compile section
	sprintf(out_fname, "%s.out", result);
	sprintf(result_fname, "%s", result);

	msystem("gcc %s -o %s", code_path, out_fname);

	//
	int output = open(result_fname, O_RDWR | O_CREAT | O_TRUNC, MODE); 
	close(1);
	dup(output);

	FILE* file = fopen(data_fname, "r");
	char data[1024] = { 0, };

	while(fgets(data, 1024, file) != NULL){
		int data_fd = open("temp", O_RDWR | O_CREAT | O_TRUNC, MODE);
		write(data_fd, data, sizeof(data));
		
		msystem("./%s < temp", out_fname);
		close(data_fd);
	}
	
	msystem("rm %s", "temp");
	
	close(output);
	fclose(file);


	return 0;
}

int compare_result(const char* target, const char* answer){
	char tdata[1024] = { 0, };
	char adata[1024] = { 0, };
	
	int tfd = open(target, O_RDONLY);
	int afd = open(answer, O_RDONLY);
	
	while(1){
		int t = read(tfd, tdata, 1024);
		int a = read(afd, adata, 1024);

		if(strcmp(tdata, adata) != 0){
			close(tfd);
			close(afd);
			return -1;
		}
		

		if((t <= 0) || (a <= 0)){
			close(tfd);
			close(afd);
			break;
		}
	}	
	return 0;
}
