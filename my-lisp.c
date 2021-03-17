#include <stdio.h>
// #include "parser/parser.h"
#include "parser/grammar/grammar.c"

static int input_size = 2048;

void process(char *input, const Grammar* my_lisp_grammar_ptr)
{	
	// token *tokenizer_result = tokenize(input);
	// /* Number of tokens are equal to number of character in source code */
	// ast_node *parser_result = parse(tokenizer_result, strlen(input)-1); //-1 because in input last character is newline and we don't need it
	// puts(parser_result->node_type);
	// puts(parser_result->node_value);
	
	mpc_result_t r;
	if (mpc_parse("<stdin>", input, my_lisp_grammar_ptr->My_Lisp, &r)) {
	/* On Success Print the AST */
	mpc_ast_print(r.output);
	mpc_ast_delete(r.output);
	} else {
	/* Otherwise Print the Error */
	mpc_err_print(r.error);
	mpc_err_delete(r.error);
	}

}

char *read()
{
	//read line into dynamically allocated input.
	char *input = malloc(input_size);
	fgets(input, input_size, stdin);
	return input;
}

int main(int argc, char **argv)
{
	puts("My-Lisp Version 0.0.0.0.1");

	puts("Press Ctl + c to Exit");

	Grammar* my_lisp_grammar_ptr = initialiseGrammarForMpc();

	while (1)
	{
		printf("My-List>");
		char *input = read();
		process(input, my_lisp_grammar_ptr);
	}
	
	// mpc_cleanup(4, my_lisp_grammar_ptr->Number, my_lisp_grammar_ptr->Operator, my_lisp_grammar_ptr->Expression, my_lisp_grammar_ptr->My_Lisp);

	return 0;
}
