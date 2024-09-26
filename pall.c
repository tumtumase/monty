#include "monty.h"

/**
 * free_stack - Frees a stack (doubly linked list).
 * @stack: Double pointer to the stack to be freed.
 */
void free_stack(stack_t **stack)
{
	stack_t *current;
	stack_t *next_node;

	if (!stack || !*stack)
		return;

	current = *stack;

	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}
