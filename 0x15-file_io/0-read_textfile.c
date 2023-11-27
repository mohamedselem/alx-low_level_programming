#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- function to Read text file print to STDOUT.
 * @filename: the text file will be read
 * @letters: number of letters will be read
 * Return: w- the number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buc;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buc = malloc(sizeof(char) * letters);
	t = read(fd, buc, letters);
	w = write(STDOUT_FILENO, buc, t);

	free(buc);
	close(fd);
	return (w);
}
