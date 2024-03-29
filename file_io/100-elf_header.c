#include "main.h"


void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);



/**
 * check_elf - program that checks if the provided array of bytes represents
 * a valid ELF file
 *
 * if the file is not an ELF file, we exit with the status code 98 and we display
 * a comprehensive error message to stderr
 *
 * @e_ident: a pointer to the start of the ELF identification bytes
 *
 * Return: nothing (void)
 */

void check_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}



/**
 * print_magic - program that prints the magic number (identification bytes)
 * of the ELF file
 *
 * @e_ident: a pointer to the start of the ELF identification bytes
 *
 * Return: nothing (void)
 */

void print_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}



/**
 * print_class - program that prints the ELF class (32-bit or 64-bit)
 * of the ELF file
 *
 * @e_ident: a pointer to the start of the ELF identification bytes
 *
 * Return: nothing (void)
 */

void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}



/**
 * print_data - program that prints the data encoding (endianess)
 * of the ELF file
 *
 * @e_ident: a pointer to the start of the ELF identification bytes
 *
 * Return: nothing (void)
 */

void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}



/**
 * print_version - program that prints the ELF version of the file
 *
 * @e_ident: a pointer to the start of the ELF identification bytes
 *
 * Return: nothing (void)
 */

void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}



/**
 * print_osabi - program that prints the operating system and ABI of the ELF file
 *
 * @e_ident: a pointer to the start of the ELF identification bytes
 *
 * Return: nothing (void)
 */

void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}



/**
 * print_abi - program that prints the ABI version of the ELF file
 *
 * @e_ident: a pointer to the start of the ELF identification bytes
 *
 * Return: nothing (void)
 */

void print_abi(unsigned char *e_ident)
{
	(void)e_ident;

	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}



/**
 * print_type - program that prints the type of the ELF file
 * ( ---> executable, shared object)
 *
 * @e_type: the type field from the ELF header
 * @e_ident: a pointer to the start of the ELF identification bytes
 *
 * Return: nothing (void)
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	(void)e_ident;

	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}



/**
 * print_entry - program that prints the entry point address of the ELF file
 *
 * @e_entry: the entry point address from the ELF header
 * @e_ident: a pointer to the start of the ELF identification bytes
 *
 * Return: nothing (void)
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	(void)e_ident;

	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}



/**
 * close_elf - program that closes the ELF file descriptor
 *
 * we exit with the error code 98 if closing fails,
 * and we display a comprehensive error message to stderr
 *
 * @elf: the file descriptor of the opened ELF file
 *
 * Return: nothing (void)
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}



/**
 * main - the entry point
 *
 * program that displays the information contained in the ELF header
 * at the start of an ELF file
 *
 * Displayed informations: (no less, no more, and we do not include trailing whitespace):
 * ---> Magic
 * ---> Class
 * ---> Data
 * ---> Version
 * ---> OS/ABI
 * ---> ABI Version
 * ---> Type
 * ---> Entry point address
 *
 * Format: the same as readelf -h (version 2.26.1)
 *
 * if the file is not an ELF file, or on error, we exit with the status code 98
 * and we display a comprehensive error message to stderr
 *
 * @argc: the number of arguments supplied to the program
 * @argv: An array of pointers to the program's arguments
 *
 * Return: 0 (success)
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);

	return (0);
}