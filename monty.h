#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct buf_struct - Global buffers.
 * @read_buff: Buffer for read.
 * @list_cmd: Tokenized read buffer.
 * @tok_cmd: Tokenize each token from previous split based on spaces.
 * @argv: Arguments from command line.
 *
 * Description: - Buffers used globally throughout files.
 */
typedef struct buf_struct
{
	char read_buff[4096];
	char *list_cmd[1000];
	char *tok_cmd[1000];
	char **argv;
} buf_struct;


/* Execute functions */

void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number);
void exec_loop(buf_struct *a);

/* End of execute functions */

/* String functions */

char **split_spaces(char *buff, buf_struct *a);
char **split_newline(buf_struct *a);
buf_struct *make_struct(char *argv[]);

/*End of string functions */

/* Doubly linked list functions */

void free_stack(stack_t *head);

/* End of Doubly linked list functions */

/* Helper functions */

int digits_only(char *str);

/* End of helper functions */

/* monty functions */

stack_t *push(stack_t **head, int n);
void pall(stack_t **h, unsigned int line_n);
void pint(stack_t **h, unsigned int line_n);
void pop(stack_t **h, unsigned int line_n);
void swap(stack_t **stack, unsigned int line_n);
void add(stack_t **stack, unsigned int line_n);
void sub(stack_t **stack, unsigned int line_n);
void _div(stack_t **stack, unsigned int line_n);
void mod(stack_t **stack, unsigned int line_n);
void mul(stack_t **stack, unsigned int line_n);
void nop(stack_t **stack, unsigned int line_n);
void pchar(stack_t **stack, unsigned int line_n);
void pstr(stack_t **stack, unsigned int line_n);
void rotl(stack_t **stack, unsigned int line_n);
void rotr(stack_t **stack, unsigned int line_n);
void queue(stack_t **stack, unsigned int line_n);

/* end of monty functions */

#endif /*MONTY_H*/
