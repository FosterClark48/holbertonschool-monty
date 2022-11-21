#include "monty.h"
/** pop - Removes node from top of stack
 * @stack: pointer to stack
 * @linenum: number line in the m file
 *
 * Return: Void
 */

void pop(stack_t **stack, unsigned int linenum)
{
	stack_t *temp;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", linenumber);
		free_global(*stack);
		exit(EXIT_FAILURE);
	}
/** unlinking the front node and then freeing it*/
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - Swaps the top two nodes on the stack
 * @stack:Pointer to stack
 * @linenum: line number
 *
 * Return: Void
 */

void swap(stack_t **stack, unsigned int linenum)
{
	stack_t *temp;
	int i = 1;

	for (temp = *stack; i < 3; i++, temp = temp->next)
	{
		if (temp == NULL)
		{
			fprintf(stderr, "L%u: can't swap, stack too short\n", linenumber);
			free_global(*stack);
			exit(EXIT_FAILURE);
		}
	}
/*assigning x to temp, then y to x, then temp to y so long as it exists */
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
/**
 * nop - uh...
 * @stack: points to stack
 * @linenum: line num
 *
 * Return : Void
 */

void nop(stack_t **stack, unsigned int linenum)
{
	(void)stack;
	(void)linenum;
}

/**
 * add - replaces first two nodes with the sum of the two at the top of the stack
 * @stack: linked list
 * @linenum: current line
 */
void add(stack_t **stack, unsigned int linenum)
{
/* temp node to store the sum of 1 and 2 */
	stack_t *temp = *stack;
	int i = 1;

	for (temp = *stack; i < 3; i++, temp = temp->next)
	{
		if (temp == NULL)
		{
			fprintf(stderr, "L%u: can't add, stack too short\n", linenumber);
			free_global(*stack);
			exit(EXIT_FAILURE);
		}
	}
/* adding 1 and 2 into the new node that is now replacing them and then freeing our temp*/
	temp->next->n = temp->next->n + temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}