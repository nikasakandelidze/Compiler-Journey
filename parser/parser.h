#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	node_type: { list, func(+,-,*,/) , number}
*/

typedef struct{
	char* node_type; // node_type-s can be {sum, product, digit, list....}
	char* node_value;
	abs_node** children_nodes;
}abs_node;


char* parse(token* tokens, int number_of_tokens);