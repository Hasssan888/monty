#ifndef MONTY_H
#define MONTY_H

/**
 * Code by - HASSAN BAKRIM , SOUFAIN CHANDAD
 */

#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define _GNU_SOURCE

/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDAD
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_x;

/**
 * Code by - HASSAN BAKRIM, SOUFAIN CHANDAD
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_x **stack, unsigned int line_number);
} instruction_y;

extern stack_x *head;
typedef void (*op_func)(stack_x **, unsigned int);

/*file operations*/
void ft_open_file(char *file_name);
int ft_parse_line(char *buffer, int line_number, int format);
void ft_read_file(FILE *);
int ft_len_chars(FILE *);
void ft_find_func(char *, char *, int, int);

/*Stack operations*/
stack_x *ft_create_node(int n);
void ft_free_nodes(void);
void ft_print_stack(stack_x **, unsigned int);
void ft_add_to_stack(stack_x **, unsigned int);
void ft_add_to_queue(stack_x **, unsigned int);

void ft_call_fun(op_func, char *, char *, int, int);

void ft_print_top(stack_x **, unsigned int);
void ft_pop_top(stack_x **, unsigned int);
void ft_nop(stack_x **, unsigned int);
void ft_swap_nodes(stack_x **, unsigned int);

/*Math operations with nodes*/
void ft_add_nodes(stack_x **, unsigned int);
void ft_sub_nodes(stack_x **, unsigned int);
void ft_div_nodes(stack_x **, unsigned int);
void ft_mul_nodes(stack_x **, unsigned int);
void ft_mod_nodes(stack_x **, unsigned int);

/*String operations*/
void ft_print_char(stack_x **, unsigned int);
void ft_print_str(stack_x **, unsigned int);
void ft_rotl(stack_x **, unsigned int);

/*Error hanlding*/
void ft_err(int error_code, ...);
void ft_more_err(int error_code, ...);
void ft_string_err(int error_code, ...);
void ft_rotr(stack_x **, unsigned int);

#endif
