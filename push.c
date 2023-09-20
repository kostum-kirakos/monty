#include "monty.h"

/**
 * push - Push a node onto the stack.
 *
 * @head: Pointer to the pointer of the head of the stack.
 * @line_number: Line number of the opcode (unused in this implementation).
 *
 * Description: This function pushes a new node with the specified value onto
 * the top of the doubly linked list stack.
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node;
	char *the_num;
	int num;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	the_num = strtok(NULL, " \n\t\r");

	if (the_num == NULL || isValidNumber(the_num) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(the_num);

	new_node->n = num;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	} else
	{
		new_node->next = *head;
	(*head)->prev = new_node;
		*head = new_node;
	}
}



/**
 * pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * isValidNumber - checks if a string is a valid number
 * @str: string to check
 * Return: 1 if true, 0 if false
 */


int isValidNumber(const char *str)
{
	if ((*str >= '0' && *str <= '9') || *str == '-')
	{
		str++;
		while (*str)
		{
			if ((*str < '0' || *str > '9') && *str != '-')
			return (0);
			str++;
		}
		return (1);
	}
	return (0);
}


/**
 * free_stack - Frees a stack_t stack.
 *
 * @head: Pointer to the top of the stack.
 *
 * Description: This function frees a stack_t stack.
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
