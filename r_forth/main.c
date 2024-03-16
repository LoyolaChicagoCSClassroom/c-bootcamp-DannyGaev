#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "int_stack.h"
#include "resolveActions.h"

int main(int argc, char *argv[])
{
    char *token = generateSpaceless(argv[1]);
    const int capacity = 4;
    int_stack_t myStack;

    int_stack_init(&myStack, capacity);

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
            int success = int_stack_push(&myStack, value);
            if (!success)
            {
                fprintf(stderr, "Stack overflow: %d\n", value);
            }
            break;
        }
        case ARITH_OP:
            myStack = resolveArith(returnToken.text, myStack);
            break;
        case WORD:
            myStack = resolveWord(returnToken.text, myStack, textLength);
            break;
        case SYMB:
            myStack = resolveSymbol(returnToken.text, myStack);
            break;
        }
        token = strtok(NULL, " ");
    }

    // Print the stack (top to bottom)
    int_stack_print(&myStack, stdout);

    // Pop values from the stack and print them.
    for (int i = 0; i < capacity; i++)
    {
        int top_value;
        int success = int_stack_pop(&myStack, &top_value);
        if (!success)
        {
            fprintf(stderr, "Stack empty\n");
        }
    }

    // int_stack_print(&myStack, stdout);

    // int_stack_push(&myStack, 1);
    // int_stack_push(&myStack, 2);
    // int_stack_push(&myStack, 3);
    // int_stack_print(&myStack, stdout);
    // int_stack_swap(&myStack);
    // int_stack_print(&myStack, stdout);
    // int_stack_add(&myStack);
    // int_stack_print(&myStack, stdout);
    // int_stack_dup(&myStack);
    // int_stack_print(&myStack, stdout);
    // int_stack_add(&myStack);
    // int_stack_print(&myStack, stdout);

    return EXIT_SUCCESS;
}