#include "parser.h"


static int default_number_of_children_nodes = 1;

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
	ast_node *root_node = malloc(sizeof(ast_node));
	root_node->node_type = strdup("program");
	/*
		Let's default a root node to have 1 child.
	*/
	root_node->children_nodes = malloc(default_number_of_children_nodes * sizeof(ast_node*));
	ast_node** next_child = root_node->children_nodes; //initialise pointer to next child
	for (int i = 0; i < number_of_tokens; i++) //is -1 needed here?
	{	
		if (strcmp(tokens[i].token_type, "parentheses")==0)
		{	
			/*
				What happens here?
			*/
		}
		else if (strcmp(tokens[i].token_type, "digit")==0)
		{	
			ast_node* digit=create_digit_node_from_token(tokens);
			memcpy(next_child, &digit, sizeof(ast_node*));
			next_child=&digit;
		}
		else if (strcmp(tokens[i].token_type, "plus")==0)
		{
			ast_node *node = malloc(sizeof(ast_node));
			node->node_value = strdup("+");		
			node->node_type = strdup("plus");
			node->children_nodes = malloc(sizeof(ast_node) * 2); //2 because we are making our lives easy today.
			node->children_nodes[0]=NULL;
			node->children_nodes[1]=NULL;
			memcpy(next_child, &node, sizeof(ast_node*));
			next_child=&node;
		}else{
			printf("\n no node for AST \n"); //todo
		}
	}
	return root_node;
}