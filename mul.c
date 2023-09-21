#include "monty.h"


/**
 * mul - Multiplies the second top element
 * of the stack with the top element
 * @stack: The stack.
 * @line_number: Line number of the instruction.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
