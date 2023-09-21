#include "monty.h"

instruction_t instructions[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {NULL, NULL}};

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


    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return 1;
    }

    file_to_open = fopen(argv[1], "r");

    if (!file_to_open)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), file_to_open) != NULL)
    {
        line_number++;
        opcode = strtok(line, " \t\n");

        if (opcode == NULL || opcode[0] == '#')
            continue; /* Skip empty lines and comments */

        for (command = instructions; command->opcode != NULL; command++)
        {
            if (strcmp(opcode, command->opcode) == 0)
            {
                command->f(&stack, line_number);
                break;
            }
        }
    }

    fclose(file_to_open);
    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }
    return 0;
}
