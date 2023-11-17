#include "monty.h"

/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDAD
 * ft_open_file - this function opens a file
 * @name_file: the file namepath
 * Return: void
 */

void ft_open_file(char *name_file)
{
	FILE *fd = fopen(name_file, "r");

	if (name_file == NULL || fd == NULL)
		ft_err(2, name_file);

	ft_read_file(fd);
	fclose(fd);
}


/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDAD
 * ft_read_file - this function reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void ft_read_file(FILE *fd)
{
	int l_num, format = 0;
	char *buffer = NULL;
	size_t l = 0;

	for (l_num = 1; getline(&buffer, &l, fd) != -1; l_num++)
	{
		format = ft_parse_line(buffer, l_num, format);
	}
	free(buffer);
}


/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDAD
 * ft_parse_line - this function separates each line into tokens to determine
 * which function to call
 * @buf: line from the file
 * @l_n: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int ft_parse_line(char *buf, int l_n, int format)
{
	char *op_code, *v;
	const char *del = "\n ";

	if (buf == NULL)
		ft_err(4);

	op_code = strtok(buf, del);
	if (op_code == NULL)
		return (format);
	v = strtok(NULL, del);

	if (strcmp(op_code, "stack") == 0)
		return (0);
	if (strcmp(op_code, "queue") == 0)
		return (1);

	ft_find_func(op_code, v, l_n, format);
	return (format);
}

/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDAD
 * find_func - this function find the appropriate function for the opcode
 * @op_code: opcode
 * @v: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @l: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void ft_find_func(char *op_code, char *v, int l, int format)
{
	int a;
	int flag;

	instruction_y ft_func_list[] = {
		{"push", ft_add_to_stack},
		{"pall", ft_print_stack},
		{"pint", ft_print_top},
		{"pop", ft_pop_top},
		{"nop", ft_nop},
		{"swap", ft_swap_nodes},
		{"add", ft_add_nodes},
		{"sub", ft_sub_nodes},
		{"div", ft_div_nodes},
		{"mul", ft_mul_nodes},
		{"mod", ft_mod_nodes},
		{"pchar", ft_print_char},
		{"pstr", ft_print_str},
		{"rotl", ft_rotl},
		{"rotr", ft_rotr},
		{NULL, NULL}
	};

	if (op_code[0] == '#')
		return;

	for (flag = 1, a = 0; ft_func_list[a].opcode != NULL; a++)
	{
		if (strcmp(op_code, ft_func_list[a].opcode) == 0)
		{
			ft_call_fun(ft_func_list[a].f, op_code, v, l, format);
			flag = 0;
		}
	}
	if (flag == 1)
		ft_err(3, l, op_code);
}


/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDAD
 * ft_call_fun - this function calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op_code: string representing the opcode.
 * @v: string representing a numeric value.
 * @l: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void ft_call_fun(op_func func, char *op_code, char *v, int l, int format)
{
	stack_x *node;
	int flag;
	int a;

	flag = 1;
	if (strcmp(op_code, "push") == 0)
	{
		if (v != NULL && v[0] == '-')
		{
			v = v + 1;
			flag = -1;
		}
		if (v == NULL)
			ft_err(5, l);
		for (a = 0; v[a] != '\0'; a++)
		{
			if (isdigit(v[a]) == 0)
				ft_err(5, l);
		}
		node = ft_create_node(atoi(v) * flag);
		if (format == 0)
			func(&node, l);
		if (format == 1)
			ft_add_to_queue(&node, l);
	}
	else
		func(&head, l);
}
