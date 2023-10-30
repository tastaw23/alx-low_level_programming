#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *xxd;
	ssize_t ss;
	ssize_t m;
	ssize_t a;

	ss = open(filename, O_RDONLY);
	if (ss == -1)
		return (0);
	xxd = malloc(sizeof(char) * letters);
	a = read(ss, xxd, letters);
	m = write(STDOUT_FILENO, xxd, a);

	free(xxd);
	close(ss);
	return (m);
}

