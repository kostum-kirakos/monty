#include "monty.h"


/**
 * mul - Multiplies the second top element
 * of the stack with the top element
 * @stack: The stack.
 * @line_number: Line number of the instruction.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int mul = 0;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mul = temp->n * temp->next->n;
	temp->next->n = mul;
	*stack = temp->next;
	free(temp);
}
