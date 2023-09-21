#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->prev;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
