#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: pointer to the top of the stack
 *
 * Return: nothing.
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
