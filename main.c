#include "monty.h"
stack_x *head = NULL;

/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ft_open_file(av[1]);
	ft_free_nodes();
	return (0);
}

/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_create_node - this function creates a node.
 * @nb: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_x *ft_create_node(int nb)
{
	stack_x *node;

	node = malloc(sizeof(stack_x));
	if (node == NULL)
		ft_err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = nb;
	return (node);
}

/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_free_nodes - this function frees nodes in the stack.
 */
void ft_free_nodes(void)
{
	stack_x *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * Code by - HASSAN BAKRIM SOUFAIN CHANDAD
 * ft_add_to_queue - this function adds a node to the queue.
 * @newnode: Pointer to the new node.
 * @l: line number of the opcode.
 */
void ft_add_to_queue(stack_x **newnode, __attribute__((unused))unsigned int l)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *newnode;
	(*newnode)->prev = tmp;

}
