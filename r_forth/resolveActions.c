#include "int_stack.h"
#include "token.h"
#include <string.h>


int success = 0;

int_stack_t resolveArith(char *answer, int_stack_t myStack)
{
    switch (*answer)
    {
    case '+':
        printf("Adding top two elements...\n");
        success = int_stack_add(&myStack);
        break;
    case '-':
        printf("Subtracting top two elements...\n");
        break;
    case '*':
        printf("Multiplying top two elements...\n");
        break;
    case '/':
        printf("Deleting top two elements...\n");
        break;
    }
    return myStack;
}

int_stack_t resolveWord(char *answer, int_stack_t myStack, int textLength)
{
    char text[textLength];
    strncpy(text, answer, textLength);
    if (strcmp(text, "rot") == 0)
    {
        printf("Rotating\n");
        success = int_stack_rot(&myStack);
    }
    else if (strcmp(text, "dup") == 0)
    {
        printf("Duplicating\n");
        success =int_stack_dup(&myStack);
    }
    else if (strcmp(text, "swap") == 0)
    {
        int_stack_swap(&myStack);
    }
    else if (strcmp(text, "drop") == 0)
    {
        int_stack_drop(&myStack);
    }
    else if (strcmp(text, "over") == 0)
    {
        int_stack_over(&myStack);
    }
    return myStack;
}

int_stack_t resolveSymbol(char *answer, int_stack_t myStack)
{
    return myStack;
}

char *resolveArithOp(char *symbol)
{
    if (*symbol == '+')
    {
        return "a";
    }
    else if (*symbol == '-')
    {
        return "s";
    }
    else if (*symbol == '*')
    {
        return "m";
    }
    else if (*symbol == '/')
    {
        return "delete";
    }
    return "NULL";
}