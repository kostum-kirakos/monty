#include "monty.h"


/**
 * _div - divide the top two elements of the stack.
 * @stack: The stack.
 * @line_number: Line number of the instruction.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n /= temp->n;
	*stack = temp->next;
	free(temp);
}
