#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line number of the current instruction in the
 * ByteCodes file
 *
 * Return: nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;
	stack_t *new;

	arg = strtok(NULL, " \t\n");

	if (arg == NULL || !is_only_digits(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		my_exit(1);
	}

	n = atoi(arg);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		my_exit(1);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	else
		info.last = new;

	*stack = new;
}

/**
 * pall - prints all the values in the stack from the top
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line_number of the current instruction in the
 * ByteCodes file
 *
 * Return: nothing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void) line_number;

	if (stack == NULL)
		return;

	curr = *stack;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * pint - prints the top value in the stack
 * @stack: stack pointer at the top
 * @line_number: the line_number
 *
 * Return: nothing.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		my_exit(1);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: stack top
 * @line_number: the line_number
 *
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{

	stack_t *top;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		my_exit(1);
	}

	top = *stack;
	*stack = top->next;
	if (top->next)
		top->next->prev = NULL;
	else
		info.last = NULL;

	free(top);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line number of the current instructions in the
 * ByteCodes file
 *
 * Return: nothing.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *a, *b;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		my_exit(1);
	}

	a = *stack;
	b = a->next;

	a->next = b->next;
	a->prev = b;

	if (b->next)
		b->next->prev = a;
	else
		info.last = a;

	b->next = a;
	b->prev = NULL;

	*stack = b;
}
