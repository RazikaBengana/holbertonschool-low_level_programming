#include "main.h"

/**
 * append_text_to_file - program that appends text at the end of a file
 *
 * this function appends the provided text content to the end of a specified file
 *
 * we do not have to create the file if it does not exist;
 * if text_content is NULL, we do not add anything to the file;
 *
 * if filename is NULL, we return -1;
 * we return 1 if the file exists and -1 if the file does not exist,
 * or if we do not have the required permissions to write the file
 *
 * @filename: the name of the file to which text content will be appended
 * @text_content: the text content, the NULL terminated string
 * to be appended to the file
 *
 * Return: 1 on success, or -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int char_count = 0, file_descriptor, write_result;

	if (filename == NULL)
		return (-1);

/* If text_content is NULL, set it to an empty string */
	if (text_content == NULL)
		text_content = "";

/* Count the number of characters in the text content */
	while (text_content[char_count] != '\0')
	{
		char_count++;
	}

/* Open the file for writing in append mode */
	file_descriptor = open(filename, O_WRONLY | O_APPEND);

/* Write the text content to the file */
	write_result = write(file_descriptor, text_content, char_count);

/* Check for errors during file opening or writing */
	if (file_descriptor == -1 || write_result == -1)
		return (-1);

/* Close the file */
	close(file_descriptor);

	return (1); /* Successful appending */
}