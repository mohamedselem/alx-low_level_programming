#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

/**
 * _checkelf - func to checks if the file is elf type
 *
 * @h: header
 *
 * Return: No Return
 */
void _checkelf(char *h)
{
	if (h[0] != 0x7f || h[1] != 'E' || h[2] != 'L' || h[3] != 'F')
		dprintf(STDERR_FILENO, "Error: Wrong file type\n"), exit(98);
}

/**
 * _magic - func to print elf magic
 *
 * @h: header
 *
 * Return: No Return
 */
void _magic(char *h)
{
	int z;

	printf("ELF Header:\n  Magic:   ");

	for (z = 0; z < 15; z++)
		printf("%02x ", (unsigned int)h[z]);
	printf("%02x", (unsigned int)h[z]);

	printf("\n");
}
/**
 * _class - func to print elf class
 *
 * @h: the header
 * @x64: 1 if x64, 0 if x32
 *
 * Return: No Return
 */
void _class(char *h, int x64)
{
	if (h[4] != 1 && h[4] != 2)
	{
		printf("<unknown: %02hx>\n", h[4]);
		return;
	}
	printf("  %-35s", "Class:");
	if (x64 == 0)
		printf("ELF32\n");
	else if (x64 == 1)
		printf("ELF64\n");
}
/**
 * _data - func to print elf data
 *
 * @h: the Header
 *
 * Return: No Return
 */
void _data(char *h)
{
	printf("  %-35s", "Data:");
	printf("2's complement, ");
	if (h[5] == 1)
		printf("little endian\n");
	else if (h[5] == 2)
		printf("big endian\n");
	else
		printf("<unknown: %02hx>\n", h[5]);
}
/**
 * _version - func can print elf versions
 *
 * @h: header
 *
 * Return: No Return
 */
void _version(char *h)
{
	printf("  %-35s", "Version:");
	if (h[6] == EV_CURRENT)
	{
		printf("%d (current)\n", h[6]);
	}
	else if (h[6] != EV_CURRENT)
	{
		printf("%d\n", h[6]);
	}
}
/**
 * _os - func can print elf os/abi
 *
 * @h: header
 *
 * Return: No Return
 */
void _os(char *h)
{
	printf("  %-35s", "OS/ABI:");

	if (h[7] == 0)
		printf("UNIX - System V\n");
	else if (h[7] == 1)
		printf("UNIX - HP-UX\n");
	else if (h[7] == 2)
		printf("UNIX - NetBSD\n");
	else if (h[7] == 3)
		printf("UNIX - Linux\n");
	else if (h[7] == 4)
		printf("UNIX - GNU Hurd\n");
	else if (h[7] == 6)
		printf("UNIX - Solaris\n");
	else if (h[7] == 7)
		printf("UNIX - AIX\n");
	else if (h[7] == 8)
		printf("UNIX - IRIX\n");
	else if (h[7] == 9)
		printf("UNIX - FreeBSD\n");
	else if (h[7] == 10)
		printf("UNIX - Tru64\n");
	else if (h[7] == 11)
		printf("UNIX - Novell Modesto\n");
	else if (h[7] == 12)
		printf("UNIX - OpenBSD\n");
	else if (h[7] == 13)
		printf("UNIX - Open VMS\n");
	else if (h[7] == 14)
		printf("UNIX - NonStop Kernel\n");
	else if (h[7] == 15)
		printf("UNIX - AROS\n");
	else if (h[7] == 16)
		printf("UNIX - Fenix OS\n");
	else if (h[7] == 17)
		printf("UNIX - CloudABI\n");
	else
		printf("<unknown: %02hx>\n", h[7]);
}
/**
 * _abiv - func to checks abi versions
 *
 * @h: the header
 *
 * Return: No Return
 */
void _abiv(char *h)
{
	printf("  %-35s", "ABI Version:");
	printf("%d\n", h[8]);
}
/**
 * _type - func do print elf type
 *
 * @h: the header
 * @x64: var to check if x64 equal (1) or x32 (0)
 *
 * Return: No Return
 */
void _type(char *h, int x64)
{
	int xtype = 17;

	(void) x64;

	if (h[5] == 1)
		xtype = 16;

	printf("  %-35s", "Type:");

	switch (h[xtype])
	{
	case 0:
		printf("NONE\n");
		break;
	case 1:
		printf("REL (Relocatable file)\n");
		break;
	case 2:
		printf("EXEC (Executable file)\n");
		break;
	case 3:
		printf("DYN (Shared object file)\n");
		break;
	case 4:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown>: %02x\n", h[xtype]);
	}
}
/**
 * _entry - func do print elf entry point access
 * the elf header struct
 *
 * @h: header
 * @x64: check 1 for x64 and 0 x32
 *
 * Return: No Return
 */
void _entry(char *h, int x64)
{
	int count = 27, i;

	printf("  %-35s0x", "Entry point address:");

	if (x64 == 1)
		count = 31;

	if (h[5] == 1)
	{
		i = count;
		while (h[i] == 0 && i > 24)
			i--;
		printf("%x", h[i]);
		i--;

		while (i >= 24)
		{
			printf("%02x", (unsigned char) h[i]);
			i--;
		}
	}
	else
	{

		i = 24;
		while (h[i] == 0)
			i++;
		printf("%x", h[i]);
		i++;

		while (i <= count)
		{
			printf("%02x", (unsigned char) h[i]);
			i++;
		}
	}
	printf("\n");
}

/**
 * main - func to displays information  in the ELF header at
 * the start of  ELF file system.
 *
 * Usage: elf_header elf_filename
 * displayed information: (not less, not more)
 * @argc: the number of parameters go into main
 * @argv: Pointer of array pointers containing string
 *
 * Return: Always 0 on (Success)
 *
 * if the file is not an ELF file, or on error, exit with status code 98
 *  and display an error message to stderr
 */
int main(int argc, char **argv)
{
	int fdelf, relf, closecheck, x64 = 0;
	char h[32];

	if (argc != 2)
		dprintf(STDERR_FILENO, "Wrong # of Arguments\n"), exit(98);
	if (argv[1] == 0)
		dprintf(STDERR_FILENO, "Null name\n"), exit(98);
	fdelf = open(argv[1], O_RDONLY);
	if (fdelf == -1)
		dprintf(STDERR_FILENO, "Can't Open File\n"), exit(98);
	relf = read(fdelf, h, 32);
	if (relf == -1)
		dprintf(STDERR_FILENO, "Error Reading File\n"), exit(98);

	_checkelf(h);

	if (h[4] == 2)
		x64 = 1;

	_magic(h);
	_class(h, x64);
	_data(h);
	_version(h);
	_os(h);
	_abiv(h);
	_type(h, x64);
	_entry(h, x64);

	closecheck = close(fdelf);

	if (closecheck == -1)
		dprintf(STDERR_FILENO, "Error Closing File\n"), exit(98);

	return (0);
}
