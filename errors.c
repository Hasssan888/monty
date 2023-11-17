#include "monty.h"

/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDAD
 * ft_err - Prints appropiate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void ft_err(int error_code, ...)
{
	va_list arg;
	char *opt;
	int len_n;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			len_n = va_arg(arg, int);
			opt = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", len_n, opt);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	ft_free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDAd
 * ft_more_err - this function handles errors.
 * @error_code: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void ft_more_err(int error_code, ...)
{
	va_list arg;
	char *opt;
	int len_n;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			len_n = va_arg(arg, unsigned int);
			opt = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", len_n, opt);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	ft_free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDAD
 * ft_string_err - this function handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void ft_string_err(int error_code, ...)
{
	va_list arg;
	int len_n;

	va_start(arg, error_code);
	len_n = va_arg(arg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", len_n);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", len_n);
			break;
		default:
			break;
	}
	ft_free_nodes();
	exit(EXIT_FAILURE);
}
