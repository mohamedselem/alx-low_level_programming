#include "main.h"

/**
 * append_text_to_file - Function to Appends text at the end of a file.
 * @filename: pointer to the name of  file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If function fails or filename is NULL - -1.
 *         If file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, lenc = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lenc = 0; text_content[lenc];)
			lenc++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, lenc);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}

