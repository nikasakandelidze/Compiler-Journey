#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../tokenizer/tokenizer.h"
/*
	node_type: { list, func(+,-,*,/) , number}
*/

typedef struct{
	char* node_type; // node_type-s can be {sum, product, digit, list....}
	char* node_value;
	ast_node** children_nodes;
}ast_node;


ast_node* parse(token* tokens, int number_of_tokens);