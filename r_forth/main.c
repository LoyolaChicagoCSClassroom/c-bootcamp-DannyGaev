#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "int_stack.h"

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
        if (returnToken.type_t == NUM)
        {
            int value = *returnToken.text - '0';
            int success = int_stack_push(&myStack, value);
            if (!success)
            {
                fprintf(stderr, "Stack overflow: %d\n", value);
            }
        }
        else if (returnToken.type_t == ARITH_OP)
        {
            char *answer = returnToken.text;
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
            }
        }
        else if (returnToken.type_t == WORD)
        {
            char text[textLength];
            strncpy(text, returnToken.text, textLength);
            if (strcmp(text, "rot") == 0)
            {
                printf("Rotating\n");
                int_stack_rot(&myStack);
            }
            else if (strcmp(text, "dup") == 0)
            {
                printf("Duplicating\n");
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