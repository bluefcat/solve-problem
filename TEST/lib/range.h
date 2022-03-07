#pragma once

#define INIT_BUFFER(BUFFER, SIZE) for(int i = 0; i < SIZE; i ++) BUFFER[i] = 0;

#define MAXLEN			1024

#define PARSING_ERR		-1
#define NONE 			0x00
#define FINDING_NAME 	0x01
#define FINDING_MIN 	0x02
#define FINDING_MAX 	0x03

#define FINDING_VALUE	0x08

#define FINDING_RANGE 	0x11
#define FINDING_CHAIN	0x12

#define ACCEPT			0xFF

/*
formating:
	TOKEN - TOKEN - TOKEN - TOKEN
							L child_header;
 */

typedef struct _RANGE_TOKEN{
	char* 					value_name;
	int	  					value_min;
	int   					value_max;
} RANGE_TOKEN;

typedef struct _CHAIN_TOKEN{
	RANGE_TOKEN* 			range_token;
	struct _CHAIN_TOKEN* 	next_token;

	//child_header is linked list
	struct _CHAIN_TOKEN*	child_header;
} CHAIN_TOKEN, TOKEN; 

//genrated range function

typedef struct _DATA_TOKEN{
	char*					value_name;
	int						value;
} DATA_TOKEN;

typedef struct _CHAIN_DATA_TOKEN{
	DATA_TOKEN*					data_token;
	struct _CHAIN_DATA_TOKEN*	next_token;

	struct _CHAIN_DATA_TOKEN*	child_header;
} CHAIN_DATA_TOKEN, RESULT;



void print_range_token(RANGE_TOKEN* result);
void print_chain_token(CHAIN_TOKEN* result);
void print_token(TOKEN* result);
int parse_range_token_(int fd, RANGE_TOKEN* result);
int parse_chain_token_(int fd, RANGE_TOKEN* tokens, CHAIN_TOKEN* target, int size);

RANGE_TOKEN* find_token_(const char* name, RANGE_TOKEN* tokens, int size);

TOKEN* 	parse_data_(int fd);

TOKEN* 	create_token(const char* file_name);   	// this function create token's linked list what parse with a file
int 	generate_token(TOKEN* token); 			// this function make the value in range with token;
void	delete_child_(TOKEN* header);
void 	delete_chain_(TOKEN* header);
void 	delete_token(TOKEN* token);				// this function is delete a token what created by create_token

