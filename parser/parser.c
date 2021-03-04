#include "parser.h"

static ast_node *create_digit_node_from_token(token *token)
{
	ast_node *node = malloc(sizeof(ast_node));
	node->node_type = strdup(token->token_type);
	node->children_nodes = NULL;
	node->node_value = token->token_value;
	return node;
}

/*
	Let's at the moment write parser only for next expression: (func first second) ==> (+ 2 1) or (* 3 1)..etc.
*/
ast_node *parse(token *tokens, int number_of_tokens)
{
	for (int i = 0; i < number_of_tokens; i++)
	{

		if (number_of_tokens == 0)
		{
			return NULL;
		}
		else if (strcmp(tokens[0].token_type, "parentheses"))
		{
		}
		else if (strcmp(tokens[0].token_type, "digit"))
		{
			create_digit_node_from_token(tokens);
		}
		else if (strcmp(tokens[0].token_type, "plus"))
		{
			ast_node *node = malloc(sizeof(ast_node));
			node->node_value = strdup("+");
			node->node_type = strdup("plus");
			node->children_nodes = malloc(sizeof(ast_node) * 2); //2 because we are making our lives easy today.
			memcpy(node->children_nodes, create_digit_node_from_token(node->children_nodes + 1), sizeof(ast_node));
			memcpy(node->children_nodes, create_digit_node_from_token(node->children_nodes + 2), sizeof(ast_node));
		}
	}

	return root_node;
}