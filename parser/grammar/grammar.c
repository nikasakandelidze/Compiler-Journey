#include "../../dependencies/mpc/mpc.h"

typedef struct Grammar{
    mpc_parser_t* My_Lisp;
    mpc_parser_t* Expression;
    mpc_parser_t* Number;
    mpc_parser_t* Operator;
}Grammar;

/* 
    Parser grammar for Polush notation: https://en.wikipedia.org/wiki/Polish_notation


    To specify grammar we use next rules/parts:
        - Program: Start of input --> Operator --> One or more expressions --> End of input
        - Expression: either number or '(' --> an Operator --> one or more Expression -->')'.
        - Operator: '+', '-', '/', '*'
        - Number: an optional '-'(minus) and one or more chars between 0-9

    We'll need Regular expressions for defining these grammar rules.
        .	Any character is required.
        a	The character a is required.
        [abcdef]	Any character in the set abcdef is required.
        [a-f]	Any character in the range a to f is required.
        a?	The character a is optional.
        a*	Zero or more of the character a are required.
        a+	One or more of the character a are required.
        ^	The start of input is required.
        $	The end of input is required.
*/

Grammar* getGrammar(){
    Grammar* grammar = malloc(sizeof(Grammar));
    grammar->Number= mpc_new("number");
    grammar->Expression=mpc_new("expression");
    grammar->Operator=mpc_new("operator");
    grammar->My_Lisp=mpc_new("my_Lisp");
    return grammar;
}

Grammar* initialiseGrammarForMpc(){
    Grammar* grammar = getGrammar();

     /*
        Use mpc library to define parsers created above using regular expressions.
    */
    mpca_lang(MPCA_LANG_DEFAULT,
    "                                                     \
        number   : /-?[0-9]+/ ;                             \
        operator : '+' | '-' | '*' | '/' ;                  \
        expr     : <number> | '(' <operator> <expr>+ ')' ;  \
        my_Lisp    : /^/ <operator> <expr>+ /$/ ;             \
    ",
    grammar->Number, grammar->Operator, grammar->Expression, grammar->My_Lisp);
    return grammar;
}



