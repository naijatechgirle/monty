#include "monty.h"

/**
  * add - adds the top two elements of the stack
  * @stack: start of doubly linked list
  * @line_n: line number
  */
void add(stack_t **stack, unsigned int line_n)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_n);
}

/**
 * sub - adds the top two elements of the stack
 * @stack: start of doubly linked list
 * @line_n: line number
 */
void sub(stack_t **stack, unsigned int line_n)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_n);
}
/**
 * _div - adds the top two elements of the stack
 * @stack: start of doubly linked list
 * @line_n: line number
 */
void _div(stack_t **stack, unsigned int line_n)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't div, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: division by zero\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_n);
}

/**
 * mod - adds the top two elements of the stack
 * @stack: start of doubly linked list
 * @line_n: line number
 */
void mod(stack_t **stack, unsigned int line_n)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: division by zero\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_n);
}

/**
 * mul - adds the top two elements of the stack
 * @stack: start of doubly linked list
 * @line_n: line number
 */
void mul(stack_t **stack, unsigned int line_n)
{
	if (!(*stack) || !(*stack)->next)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_n);
}
