#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "int_stack.h"

int main(int argc, char *argv[])
{
    char *token = generateSpaceless(argv[1]);
    int_stack_t myStack;
    const int capacity = 5;

    // Initialize the stack with a capacity of 5.
    int_stack_init(&myStack, capacity);

    // Push values onto the stack.
    for (int i = 0; i < capacity; i++)
    {
        int success = int_stack_push(&myStack, i);
        if (!success)
        {
            fprintf(stderr, "Stack overflow: %d\n", i);
        }
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

    // Print the stack (top to bottom)
    int_stack_print(&myStack, stdout);

    // Quick tests for swap, dup, and add.

    int_stack_push(&myStack, 7);
    int_stack_push(&myStack, 8);
    int_stack_print(&myStack, stdout);
    int_stack_swap(&myStack);
    int_stack_print(&myStack, stdout);
    int_stack_add(&myStack);
    int_stack_print(&myStack, stdout); // hopefully, 15 only item on stack!
    int_stack_dup(&myStack);
    int_stack_print(&myStack, stdout); // hopefully, 15 only item on stack!
    int_stack_add(&myStack);
    int_stack_print(&myStack, stdout); // hopefully, 30 only item on stack!

    while (token != NULL)
    {
        TOKEN returnToken = parseTokens(token);
        printf("CLASS: %s, TEXT: %s\n", resolveToString(returnToken.type_t), returnToken.text);
        token = strtok(NULL, " ");
    }
    return EXIT_SUCCESS;
}