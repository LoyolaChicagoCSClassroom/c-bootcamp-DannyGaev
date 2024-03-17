#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "int_stack.h"
#include "general_stack.h"
#include "resolveActions.h"

int main(int argc, char *argv[])
{
    char *token = generateSpaceless(argv[1]);
    const int capacity = 4;
    int_stack_t myIntStack;
    general_stack_t myGenStack;

    int_stack_init(&myIntStack, capacity);

    while (token != NULL)
    {
        TOKEN returnToken = parseTokens(token);

        printf("CLASS: %s, TEXT: %s\n", resolveToString(returnToken.type_t), returnToken.text);
        const int textLength = strlen(returnToken.text);
        switch (returnToken.type_t)
        {
        case NUM:
        {
            int value = *returnToken.text - '0';
            int success = int_stack_push(&myIntStack, value);
            if (!success)
            {
                fprintf(stderr, "Stack overflow: %d\n", value);
            }
            break;
        }
        case ARITH_OP:
            myIntStack = resolveArith(returnToken.text, myIntStack);
            break;
        case WORD:
            myIntStack = resolveWord(returnToken.text, myIntStack, textLength);
            break;
        case SYMB:
            myIntStack = resolveSymbol(returnToken.text, myIntStack);
            break;
        }
        token = strtok(NULL, " ");
    }

    int_stack_print(&myIntStack, stdout);

  
    for (int i = 0; i < capacity; i++)
    {
        int top_value;
        int success = int_stack_pop(&myIntStack, &top_value);
        if (!success)
        {
            fprintf(stderr, "Stack empty\n");
        }
    }

    return EXIT_SUCCESS;
}