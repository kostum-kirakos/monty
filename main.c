#include "monty.h"

instruction_t instructions[] = {
	{"mul", mul},
	{"add", add},
	{"swap", swap},
	{"pop", pop},
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"nop", nop},
	{"sub", sub},
	{"div", _div},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{"rotl", rotl},
	{"rotr", rotr},
	{NULL, NULL}
};

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of arguments.
 * @argv: Array of argument strings.
 * Return: 0 on success, 1 on failure.
 */

int main(int argc, char *argv[])
{
	FILE *file_to_open;
	stack_t *stack = NULL;
	char line[1024];
	unsigned int line_number = 0;
	char *opcode;
	instruction_t *command;
	int find;

	check_args_error(argc);
	file_to_open = fopen(argv[1], "r");
	check_openfile_error(file_to_open, argv[1]);
	while (fgets(line, sizeof(line), file_to_open) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue; /* Skip empty lines and comments */
		find = 0;
		for (command = instructions; command->opcode != NULL; command++)
		{
			if (strcmp(opcode, command->opcode) == 0)
			{
				command->f(&stack, line_number);
				find = 1;
				break; }
		}
		if (!find)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file_to_open);
			return (1); }
	}
	fclose(file_to_open);
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp); }
	return (0);
}


/**
 * check_args_error - Check if the number of arguments is correct.
 * @argc: Number of arguments.
 * Return: Nothing.
 */
void check_args_error(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}


/**
 * check_openfile_error - Check if the file can be opened.
 * @file_to_open: File to open.
 * @argv: Array of argument strings.
 * Return: Nothing.
 */

void check_openfile_error(FILE *file_to_open, char *argv)
{
	if (!file_to_open)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
