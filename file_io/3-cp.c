#include "main.h"

/**
 * file_error - program that handles file-related errors
 * and exits the program with appropriate error codes
 *
 * this function checks if there are errors related to file operations, and exits the program
 * with specific error codes and error messages if errors are encountered
 *
 * @file_from: the file descriptor of the source file
 * @file_to: the file descriptor of the destination file
 * @argv: the command line arguments passed to the program
 *
 * Return: nothing (void)
 */

void file_error(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - the entry point
 *
 * program that copies the content of a file to another file
 *
 * we truncate file_to if it exists;
 * permissions of the created file: rw-rw-r--;
 * we read 1,024 bytes at a time from file_from, and use buffer for fewer system calls;
 *
 * incorrect arguments counts: Exit code 97, print "Usage: cp file_from file_to" on POSIX standard error
 * nonexistent/unreadable file_from: Exit code 98, print "Can't read from file NAME_OF_THE_FILE" on POSIX standard error
 * can't create or write to file_to: Exit code 99, print "Can't write to NAME_OF_THE_FILE" on POSIX standard error
 * failed file descriptor close: Exit code 100, print "Can't close fd FD_VALUE" on POSIX standard error
 *
 * @argc: the number of command line arguments
 * @argv: the command line arguments passed to the program
 *
 * Return: 0 on successful execution, otherwise appropriate error codes
 */

int main(int argc, char *argv[])
{
	int file_from, file_to, close_result;
	ssize_t num_chars_read, num_chars_written;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	file_error(file_from, file_to, argv);

	num_chars_read = 1024;
	while (num_chars_read == 1024)
	{
		num_chars_read = read(file_from, buffer, 1024);
		if (num_chars_read == -1)
			file_error(-1, 0, argv);
		num_chars_written = write(file_to, buffer, num_chars_read);
		if (num_chars_written == -1)
			file_error(0, -1, argv);
	}

	close_result = close(file_from);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	close_result = close(file_to);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	return (0);
}