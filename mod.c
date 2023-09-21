#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: The stack.
 * @line_number: Line number of the instruction.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp || !temp->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n %= temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
