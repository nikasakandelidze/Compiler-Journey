#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct token
{
	char *token_type;
	char *token_value;
} token;

token *tokenize(char *input);
