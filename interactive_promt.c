#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser/parser.h"
#include "tokenizer/tokenizer.h"

static int input_size=2048;


void process(char* input){
		token* tokenizer_result=tokenize(input);
		/* Number of tokens are equal to number of character in source code */
		abs_node* parser_result=parse(tokenizer_result, strlen(input));
}

char* read(){
	//read line into dynamically allocated input.
	char* input = malloc(input_size); 
	fgets(input, input_size, stdin);
}


int main(int argc, char** argv){

	puts("My-Lisp Version 0.0.0.0.1");
	
	puts("Press Ctl + c to Exit");

	tokenize_input();

	while(1){
		printf("My-List>");
		char* input=read();
		process(input);
	}

	return 0;
}
