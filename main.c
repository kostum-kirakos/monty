#include "monty.h"

/**
 * main - Entry point
 *
 * @argc: Number of arguments passed to the program.
 * @argv: Array of strings containing the arguments passed to the program.
 *
 * Description: This function is the entry point for the program. It opens the
 * file passed as an argument to the program and reads the lines of the file
 * one by one. It then tokenizes each line and compares the first token to the
 * list of opcodes. If a match is found, the corresponding function is called.
 * If no match is found, an error is printed and the program exits.
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */

int main(int argc, char *argv[])
{
	FILE *file_to_open;
	char *part = NULL, *line = NULL;
	int i;
	unsigned int line_number = 0;
	stack_t *top = NULL;
	size_t len_line = 0; /* Size of the buffer */
	ssize_t read;        /* Number of characters read */

	instruction_t operation[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_to_open = fopen(argv[1], "r");
	check_file(file_to_open);

	while ((read = getline(&line, &len_line, file_to_open)) != -1)
	{
		line_number++;
		part = strtok(line, " \n\t\r");
		if (part == NULL || part[0] == '#')
		{
			line_number++;
			continue;
		}
		for (i = 0; operation[i].opcode != NULL; i++)
		{
			if (strcmp(part, operation[i].opcode) == 0)
				operation[i].f(&top, line_number); }
	}
	fclose(file_to_open);
	free(line);
	free_stack(top);
	return (EXIT_SUCCESS);
}
