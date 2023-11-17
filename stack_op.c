#include "monty.h"

/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_mul_nodes - this function adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void ft_mul_nodes(stack_x **stack, unsigned int l_n)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		ft_more_err(8, l_n, "mul");

	(*stack) = (*stack)->next;
	s = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_mod_nodes - this function adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void ft_mod_nodes(stack_x **stack, unsigned int l_n)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		ft_more_err(8, l_n, "mod");


	if ((*stack)->n == 0)
		ft_more_err(9, l_n);
	(*stack) = (*stack)->next;
	s = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
