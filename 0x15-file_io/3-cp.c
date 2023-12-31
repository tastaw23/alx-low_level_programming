#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_resto(char *file);
void close_file(int fd);

/**
 * creates_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *creates_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int de, a, v, m;
	char *resto;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	resto = create_resto(argv[2]);
	de = open(argv[1], O_RDONLY);
	v = read(de, resto, 1024);
	a = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (de == -1 || v == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(resto);
			exit(98);
		}

		m = write(a, resto, v);
		if (a == -1 || m == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(resto);
			exit(99);
		}

		v = read(de, resto, 1024);
		a = open(argv[2], O_WRONLY | O_APPEND);

	} while (v > 0);

	free(resto);
	close_file(de);
	close_file(a);

	return (0);
}

