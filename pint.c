#include "monty.h"

/**
 * pint - prints the value at the top of the stack
* @stack: pointer to the stack
* @line_number: linr number
* Return: void
*/

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);
}
