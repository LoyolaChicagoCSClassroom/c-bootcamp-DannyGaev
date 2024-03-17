#ifndef RESOLVEACTIONS_H
#define RESOLVEACTIONS_H

int_stack_t resolveArith(char *answer, int_stack_t myIntStack);

int_stack_t resolveWord(char *answer, int_stack_t myIntStack, int textLength);

int_stack_t resolveSymbol(char *answer, int_stack_t myIntStack);

general_stack_t resolveVariable(char *answer, general_stack_t mgs, int textLength);

#endif