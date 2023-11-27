#include "main.h"

/**
 * create_file - function do Creates a file.
 * @filename: The pointer to the file will be created.
 * @text_content: A pointer to string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fk, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fk = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fk, text_content, len);

	if (fk == -1 || w == -1)
		return (-1);

	close(fk);

	return (1);
}

