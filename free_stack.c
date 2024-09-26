#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - Frees a stack.
 * @stack: Pointer to the stack to free.
 */
void free_stack(stack_t **stack)
{
    stack_t *current;

    while (*stack)
    {
        current = *stack;
        *stack = (*stack)->next;
        free(current);
    }
}

