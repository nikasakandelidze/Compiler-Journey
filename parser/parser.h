#include "../tokenizer/tokenizer.h"
/*
	node_type: { list, func(+,-,*,/) , number}
*/

typedef struct ast_node
{
	char *node_type; // node_type-s can be {sum, product, digit, list....}
	char *node_value;
	struct ast_node **children_nodes;
} ast_node;

ast_node *parse(token *tokens, int number_of_tokens);