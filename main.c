#include "monty.h"
/**
 * make_struct - Set values for struct.
 * @argv: Argument list.
 * Return: Struct for buffers.
 */
buf_struct *make_struct(char *argv[])
{
	static buf_struct a;

	a.argv = argv;
	memset(a.read_buff, 0, sizeof(a.read_buff));
	memset(a.list_cmd, 0, sizeof(a.list_cmd));
	memset(a.tok_cmd, 0, sizeof(a.tok_cmd));

	return (&a);
}
/**
 * main - Takes argument list and executes file given.
 * @argc: Argument count.
 * @argv: List of arguments.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int fd;
	buf_struct *a;

	a = make_struct(argv);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	while ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read(fd, a->read_buff, 4096);
	close(fd);
	split_newline(a);
	exec_loop(a);

	return (0);
}
