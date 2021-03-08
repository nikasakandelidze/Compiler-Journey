#include "tokenizer.h"


static int initial_allocated_size = 100;

/*
	Let's assume that only one chracter tokens are present.
	This method will need modifications since this tokenizer doesn't cover all needed parts.
*/
token *tokenize(char *input)
{

	int current_size = 0;

	int allocated_size = initial_allocated_size;

	token *tokens = malloc(allocated_size * sizeof(token));

	int input_length = strlen(input);

	for (int i = 0; i < input_length; i++)
	{
		/* If tokens array needs to be larger reallocate memory for it. */
		if (current_size == allocated_size)
		{
			allocated_size *= 2;
			tokens = realloc(tokens, allocated_size);
		}
		/* Construct a new token for i'th element */
		token *new_token = malloc(sizeof(token));
		char token_value_str[2] = "\0"; //gives {"\0","\0"}
		token_value_str[0] = input[i];
		new_token->token_value = strdup(token_value_str);
		/* Depending on the value of token assign correct token_type to new construct. */
		if (input[i] == '(' || input[i] == ')')
		{
			new_token->token_type = strdup("parentheses");
		}
		else if (isdigit(input[i]))
		{
			new_token->token_type = strdup("digit");
		}
		else if (input[i] == '+')
		{
			new_token->token_type = strdup("plus");
		}
		else if (input[i] == '*')
		{
			new_token->token_type = strdup("product");
		}else{
			continue;
			current_size++;
		}

		/* Copy newly construct token into array of tokens.*/
		memcpy(tokens + i, new_token, sizeof(token));
	}
	return tokens;
}