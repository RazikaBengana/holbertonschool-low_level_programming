#include "main.h"

/**
 * read_textfile - program that reads a text file and prints it to the POSIX standard output
 *
 * @filename: a pointer to the name of the file
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters read and printed,
 * or 0 if: - if the file can not be opened or read
 *          - filename is NULL
 *          - write fails or does not write the expected amount of bytes
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file_descriptor, bytes_read, bytes_written;
	char *buffer;

/* Allocate memory for the buffer to hold the file content */
	buffer = malloc(letters);

	if (buffer == NULL)
		return (0);

/* Check if the filename is NULL */
	if (filename == NULL)
		return (0);

/* Open the file for reading */
	file_descriptor = open(filename, O_RDONLY);

	if (file_descriptor == -1)
		return (0);

/* Read up to 'letters' bytes from the file into the buffer */
	bytes_read = read(file_descriptor, buffer, letters);

/* Write the read content to standard output */
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

/* Check for errors during reading or writing */
	if (bytes_read == -1 || bytes_written == -1 || bytes_written != bytes_read)
	{
		free(buffer);
		return (0);
	}

/* Clean up resources and close the file */
	free(buffer);
	close(file_descriptor);

/* Return the number of bytes successfully read and written */
	return (bytes_written);
}