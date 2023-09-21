#include "monty.h"

/**
 * sub - Substract the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	(*stack)->next->n = ((*stack)->n) - ((*stack)->next->n);
	temp = *stack;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}

