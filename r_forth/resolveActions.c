#include "int_stack.h"
#include "token.h"
#include <string.h>

int_stack_t resolveArith(char *answer, int_stack_t myStack)
{
    switch (*answer)
    {
    case '+':
        printf("Adding top two elements...\n");
        int_stack_add(&myStack);
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
    case '<':
        printf("Comparing if less than...\n");
        int_stack_less_than(&myStack);
        break;
    case '>':
        printf("Comparing if greater than...\n");
        int_stack_greater_than(&myStack);
        break;
    }
    return myStack;
}

int_stack_t resolveWord(char *answer, int_stack_t myStack, int textLength)
{
    char text[textLength+1];
    strncpy(text, answer, textLength);
    text[textLength] = '\0';

    if (strcmp(text, "rot") == 0)
    {
        int_stack_rot(&myStack);
    }
    else if (strcmp(text, "dup") == 0)
    {
        int_stack_dup(&myStack);
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
    switch(*answer)
    {
        case '.':
        {
            int top_value;
            int_stack_pop(&myStack,&top_value);
            printf("Popped off: %d\n",top_value);
            break;
        }
            
    }
    return myStack;
}

// char *resolveArithOp(char *symbol)
// {
//     switch(*symbol)
//     {
//         case '+':
//             return "a";
//             break;
//         case '-':
//             return "s";
//             break;
//         case '*':
//             return "m";
//             break;
//         case '/':
//             return "d";
//             break;
//         case '<':
//             return "l";
//             break;
//         case '>':
//             return "g";
//             break;
//     }
//     return "NULL";
// }