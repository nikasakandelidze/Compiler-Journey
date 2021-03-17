#ifndef mpc_included 

#include "dependencies/mpc/mpc.h"

#define mpc_included 1

#endif 

long numbers_eval_operation(long x, char* op, long y) {
  if (strcmp(op, "+") == 0) { return x + y; }
  if (strcmp(op, "-") == 0) { return x - y; }
  if (strcmp(op, "*") == 0) { return x * y; }
  if (strcmp(op, "/") == 0) { return x / y; }
  return 0;
}

long numberEvaluator(mpc_ast_t* t){
    /* If tagged with number than get number from string */
    if(strstr(t->tag,"number")){
       return atoi(t->contents); 
    }

    /* Operator is second child( first child is open parentheses ) */
    char* op = t->children[1]->contents;

    /* Store third child in 'x' */
    long x = numberEvaluator(t->children[2]);

    /* Iterate remaining children and evaluate them */
    int i=3;
    while(strstr(t->children[i]->tag, "expr")){
        x=numbers_eval_operation(x, op, numberEvaluator(t->children[i]->contents));
        i++;
    }
    return x;
}