#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack or queue..
 * @n: int.
 * @prev: points to previous element of stack or queue..
 * @next: points to next element of stack or queue..
 *
 * Description: doubly linked list node struct..
 * for stack, queues, LIFO, FIFO..
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function..
 * @opcode: opcode..
 * @f: funct. to handle opcode..
 *
 * Description: opcode and its function..
 * for stack, queues, LIFO, FIFO..
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*Math operations with nodes*/
void mul_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void add_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/*Error hanlding*/
void string_err(int error_code, ...);
void err(int error_code, ...);
void rotr(stack_t **, unsigned int);
void more_err(int error_code, ...);

/*file operations*/
int parse_line(char *buffer, int line_number, int format);
void open_file(char *file_name);
int len_chars(FILE *);
void find_func(char *, char *, int, int);
void read_file(FILE *);

void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);

/*Stack operations*/

void free_nodes(void);

void print_stack(stack_t **, unsigned int);

void add_to_stack(stack_t **, unsigned int);

stack_t *create_node(int n);

void add_to_queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

/*String operations*/

void print_str(stack_t **, unsigned int);
void print_char(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

#endif
