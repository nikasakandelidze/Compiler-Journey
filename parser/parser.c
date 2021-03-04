#include "parser.h"

/*
	Let's at the moment write parser only for next expression: (func first second) ==> (+ 2 1) or (* 3 1)..etc.
*/
abs_node* parse(token* tokens, int number_of_tokens){
	
	abs_node* root_node=malloc(sizeof(abs_node)); 
	root_node->node_type=strdup("list");
	root_node->node_value=NULL;
	root_node->num_of_imbalanced_parentheses=0;
	
	for(int i=0; i<number_of_tokens; i++){
		if(strcmp(tokens[i].token_type,"parentheses")){
			
		}else if(strcmp(tokens[i].token_type,"plus")){
			abs_node* node=malloc(sizeof(abs_node)); 
			node->value=strdup("+");
			node->node_type=strdup("plus");
			node->children_nodes=malloc(sizeof(abs_node)*2);  //2 because we are making our lives easy today.
			for(int child_offset=0; child_offset<1; child_offset++){
				

			}

		}else if(strcmp(tokens[i].token_type,"product")){

		}else if(strcmp(tokens[i].token_type,"digit")){
			abs_node* node=malloc(sizeof(abs_node)); 
			node->node_type=strdup("digit");
			node->children_nodes=NULL;

		}
	}	

	return root_node;
}