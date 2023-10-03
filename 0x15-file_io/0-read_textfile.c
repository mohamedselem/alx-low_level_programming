#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print to posix standard output.
 * @filename: text file that will be read
 * @letters: number of letters thato will be read
 * Return: w - the number of bytes which read and printed
 *        0 if function fails or filename equal to NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}

