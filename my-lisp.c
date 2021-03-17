#include <stdio.h>
#include "parser/grammar/grammar.c"
#include "backend/evaluator.c"

static int input_size = 2048;

void process(char *input, const Grammar* my_lisp_grammar_ptr)
{	
	mpc_result_t r;
	if (mpc_parse("<stdin>", input, my_lisp_grammar_ptr->My_Lisp, &r)) {
		/* On Success Print the AST */
		long reuslt = numberEvaluator(r.output);
		printf("%li\n",result);
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
