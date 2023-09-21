#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: The stack.
 * @line_number: Line number of the command being executed.
 *
 * Return: Nothing.
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current && current->n > 0 && current->n < 128)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
