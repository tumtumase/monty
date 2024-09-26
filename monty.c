#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char line[1024]; /* Buffer for input */
    size_t len = sizeof(line);
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, len, file) != NULL)
    {
        line_number++;
        /* Process line here */
    }
    fclose(file);
    return (EXIT_SUCCESS);
}

/**
 * execute_instruction - Executes the opcode.
 * @opcode: Opcode to execute
 * @stack: Double pointer to the stack
 * @line_number: Current line number in the bytecode file
 * @arg: Argument for push opcode
 */
void execute_instruction(char *opcode, stack_t **stack,
                         unsigned int line_number, char *arg)
{
    instruction_t instructions[] = {
        {"push", push}, // Ensure this matches the type expected
        {"pall", pall},
        {NULL, NULL}
    };
    int i;

    for (i = 0; instructions[i].opcode; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            if (strcmp(opcode, "push") == 0 && !arg)
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            if (strcmp(opcode, "push") == 0)
            {
                instructions[i].f(stack, line_number, arg); // Pass arg to push
            }
            else
            {
                instructions[i].f(stack, line_number); // For other ops
            }
            return;
        }
    }
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
