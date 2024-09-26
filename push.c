#include "monty.h"

/**
 * is_digit - Checks if a string represents an integer
 * @str: String to check
 *
 * Return: 1 if the string is an integer, 0 otherwise
 */
int is_digit(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * push - Pushes an integer onto the stack
 * @stack: Double pointer to the stack
 * @line_number: Line number of the command
 * @arg: The argument (integer) to push
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	int n;

	if (!is_digit(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
