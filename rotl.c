#include "monty.h"


/**
 * rotl - Rotates the stack to the top.
 * @stack: The stack.
 * @line_number: Line number of the command being executed.
 *
 * Return: Nothing.
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int temp;

	(void)line_number;

	if (current && current->next)
	{
		temp = current->n;
		while (current->next)
		{
			current->n = current->next->n;
			current = current->next;
		}
		current->n = temp;
	}
}
