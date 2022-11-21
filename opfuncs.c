#include "monty.h"
/**
*push - Adds element to a stack
*@stack: linked list stack to push to
*@linenum: current line number of bytecode file
*Return: void
*/
void push(stack_t **stack, unsigned int linenum)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack(stack);
		err();
	}
	(void)linenum;

	if (*stack)
	{
		(*stack)->prev = newNode;
	}
	newNode->prev = NULL;
	newNode->next = *stack;
	newNode->n = 0;
	*stack = newNode;
}

/**
*pint - prints all vals on stack starting from top
*@stack: head node
*@linenum: current line number of file
*Return: void
*/
void pall(stack_t **stack, unsigned int linenum)
{
	stack_t *node = *stack;
	(void)linenum;

	while (node)
	{
		printf(("%d\n", node->n);
		node = node->next;
	}
}

/**
*pint - prints val at top of stack
*@stack: head node
*@linenum: current line number of file
*Return: void
*/
void pint(stack_t **stack, unsigned int linenum)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", linenum);
		fclose(file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}