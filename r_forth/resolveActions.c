#include "int_stack.h"
#include "general_stack.h"
#include "token.h"
#include <string.h>

int_stack_t resolveArith(char *answer, int_stack_t mis)
{
    switch (*answer)
    {
    case '+':
        //printf("Adding top two elements...\n");
        int_stack_add(&mis);
        break;
    case '-':
        //printf("Subtracting top two elements...\n");
        break;
    case '*':
        //printf("Multiplying top two elements...\n");
        break;
    case '/':
        //printf("Deleting top two elements...\n");
        break;
    }
    return mis;
}

int_stack_t resolveWord(char *answer, int_stack_t mis, int textLength)
{
    char text[textLength+1];
    strncpy(text, answer, textLength);
    text[textLength] = '\0';

    if (strcmp(text, "rot") == 0)
    {
        int_stack_rot(&mis);
    }
    else if (strcmp(text, "dup") == 0)
    {
        int_stack_dup(&mis);
    }
    else if (strcmp(text, "swap") == 0)
    {
        int_stack_swap(&mis);
    }
    else if (strcmp(text, "drop") == 0)
    {
        int_stack_drop(&mis);
    }
    else if (strcmp(text, "over") == 0)
    {
        int_stack_over(&mis);
    }
    return mis;
}

general_stack_t resolveVariable(char *answer, general_stack_t mgs, int textLength)
{ 
    char text[textLength + 1];
    strncpy(text, answer, textLength);
    text[textLength] = '\0';

    if (strcmp(text, "variable") == 0)
    {
        general_stack_declare_variable(&mgs);
    }
    return mgs;
}

int_stack_t resolveSymbol(char *answer, int_stack_t mis)
{
    switch(*answer)
    {
        case '.':
        {
            int top_value;
            int_stack_pop(&mis, &top_value);
            printf("Popped off: %d\n",top_value);
            break;
        }
        case '<':
            printf("Comparing if less than...\n");
            int_stack_less_than(&mis);
            break;
        case '>':
            printf("Comparing if greater than...\n");
            int_stack_greater_than(&mis);
            break;
        case '=':
            printf("Comparing if equal...\n");
            int_stack_equals(&mis);
            break;
    }

    return mis;
}