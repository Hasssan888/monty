#include "monty.h"

/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDDA
 * ft_print_char - this function prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void ft_print_char(stack_x **stack, unsigned int l_n)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		ft_string_err(11, l_n);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		ft_string_err(10, l_n);
	printf("%c\n", ascii);
}

/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDDA
 * ft_print_str - this function prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l: Interger representing the line number of of the opcode.
 */
void ft_print_str(stack_x **stack, __attribute__((unused))unsigned int l)
{
	int ascii;
	stack_x *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDDA
 * ft_rotl - this function rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l: Interger representing the line number of of the opcode.
 */
void ft_rotl(stack_x **stack, __attribute__((unused))unsigned int l)
{
	stack_x *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDDA
 * ft_rotr - this function rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l: Interger representing the line number of of the opcode.
 */
void ft_rotr(stack_x **stack, __attribute__((unused))unsigned int l)
{
	stack_x *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
