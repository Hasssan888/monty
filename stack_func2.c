#include "monty.h"

/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_nop - this function does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void ft_nop(stack_x **stack, unsigned int l_n)
{
	(void)stack;
	(void)l_n;
}


/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_swap_nodes - this function swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void ft_swap_nodes(stack_x **stack, unsigned int l_n)
{
	stack_x *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		ft_more_err(8, l_n, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_add_nodes - this function adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void ft_add_nodes(stack_x **stack, unsigned int l_n)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		ft_more_err(8, l_n, "add");

	(*stack) = (*stack)->next;
	s = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_sub_nodes - this function adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void ft_sub_nodes(stack_x **stack, unsigned int l_n)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		ft_more_err(8, l_n, "sub");


	(*stack) = (*stack)->next;
	s = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_div_nodes - this function adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void ft_div_nodes(stack_x **stack, unsigned int l_n)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		ft_more_err(8, l_n, "div");

	if ((*stack)->n == 0)
		ft_more_err(9, l_n);
	(*stack) = (*stack)->next;
	s = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
