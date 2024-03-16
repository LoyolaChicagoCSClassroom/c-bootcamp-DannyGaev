#ifndef RESOLVEACTIONS_H
#define RESOLVEACTIONS_H

int_stack_t resolveArith(char *answer, int_stack_t myStack);

int_stack_t resolveWord(char *answer, int_stack_t myStack, int textLength);

int_stack_t resolveSymbol(char *answer, int_stack_t myStack);

char *resolveArithOp(char *symbol);

#endif