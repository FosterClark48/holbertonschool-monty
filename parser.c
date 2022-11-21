#include "monty.h"
/**
*parser - gets matching function from opcode
*@opcode: opcode given from parsing line
*Return: function pointer
*/
void (*parser(char *opcode))(stack_t **stack, unsigned int linenum)
{
	usigned int i;

	instruction_t opFunction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; opFunction[i].opcode; i++)
	{
		if (strcmp(opFunction[i].opcode, opcode) == 0)
		{
			return (opFunction[i].f);
		}
	}
	return (NULL);
}
/**
*free_stack - frees a linked list stack
*@stack: stack to free
*/
void free_stack(stack_t **stack)
{
	if (!(stack) || !(*stack))
	{
		return;
	}
	free_stack(&((*stack)->next));
	free(*stack);
	*stack = NULL
}
/**
*err - error handler
*/
void err(void)
{
	fclose(file);
	exit(EXIT_FAILURE);
}
