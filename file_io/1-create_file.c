#include "main.h"

/**
 * create_file - program that creates a file and writes text content to it
 *
 * the created file must have those permissions: rw-------;
 * if the file already exists, we do not have to change the permissions;
 * if the file already exists, we have to truncate it;
 * if text_content is NULL, we create an empty file;
 *
 * @filename: the name of the file to create
 * @text_content: the text content, a NULL terminated string to write into the file
 *
 * Return: 1 on success, or -1 on failure (if filename is NULL)
 */

int create_file(const char *filename, char *text_content)
{
	int file_descriptor, bytes_written, content_length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = ""; /* Set an empty string if text_content is NULL */

/* Calculate the length of the text content */
	while (text_content[content_length] != '\0')
	{
		content_length++;
	}

/* Create the file and open it for writing, truncating if it already exists */
	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

/* Write the text content to the file */
	bytes_written = write(file_descriptor, text_content, content_length);

/* Check for errors in opening the file and writing content */
	if (file_descriptor == -1 && bytes_written == -1)
		return (-1);

	close(file_descriptor);

	return (1);
}