#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line number of the current instruction in the
 * ByteCodes file
 *
 * Return: nothing.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int a, b;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		my_exit(1);
	}

	top = *stack;
	a = top->n;
	b = top->next->n;

	top->next->n = b + a;

	pop(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: line number of current instruction in the Bytecodes file
 *
 * Return: nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * sub - subtracts the top element of the stack from the second top element
 * of the stack
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line number of the current instructions in the
 * ByteCodes file
 *
 * Return: nothing.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int a, b;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		my_exit(1);
	}

	top = *stack;
	a = top->n;
	b = top->next->n;

	top->next->n = b - a;

	pop(stack, line_number);
}

/**
 * _div - divides the second top element of the stack by the top element of the
 * stack
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line number of the current instruction in the
 * ByteCodes file
 *
 * Return: nothing.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int a, b;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		my_exit(1);
	}

	top = *stack;
	a = top->n;
	if (a == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		my_exit(1);
	}

	b = top->next->n;

	top->next->n = b / a;

	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * of the stack
 * @stack: a pointer to a pointer to the top of the stack
 * @line_number: the line number of the current instructions in the
 * ByteCodes file
 *
 * Return: nothing.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int a, b;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		my_exit(1);
	}

	top = *stack;
	a = top->n;
	b = top->next->n;

	top->next->n = b * a;

	pop(stack, line_number);
}
