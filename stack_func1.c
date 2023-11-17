#include "monty.h"


/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_add_to_stack - this function adds a node to the stack.
 * @newnode: Pointer to the new node.
 * @l: Interger representing the line number of of the opcode.
 */
void ft_add_to_stack(stack_x **newnode, __attribute__((unused))unsigned int l)
{
	stack_x *tmp;

	if (newnode == NULL || *newnode == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newnode;
		return;
	}
	tmp = head;
	head = *newnode;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_print_stack - this function adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: line number of  the opcode.
 */
void ft_print_stack(stack_x **stack, unsigned int l_n)
{
	stack_x *tmp;

	(void) l_n;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_pop_top - this function adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void ft_pop_top(stack_x **stack, unsigned int l_n)
{
	stack_x *tmp;

	if (stack == NULL || *stack == NULL)
		ft_more_err(7, l_n);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_print_top - this function prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_n: Interger representing the line number of of the opcode.
 */
void ft_print_top(stack_x **stack, unsigned int l_n)
{
	if (stack == NULL || *stack == NULL)
		ft_more_err(6, l_n);
	printf("%d\n", (*stack)->n);
}
