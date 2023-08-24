#include "shell.h"

/**
 * _erratoi - parsing
 * @s: source string or input string
 * Return: 0 if no numbers in string, parsed number else
 *       -1 on error handling
 */
int _erratoi(char *s)
{
	int o = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (o = 0;  s[o] != '\0'; o++)
	{
		if (s[o] >= '0' && s[o] <= '9')
		{
			result *= 10;
			result += (s[o] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - logs an error message
 * @info: the function signature
 * @estr: error message
 * Return: 0 if no numbers in string, parsed number else
 *        -1 on error handling
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - printsDecimalInteger
 * @input: the argument
 * @fd: output file descriptor
 *
 * Return: size of the printed output
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int z, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (z = 1000000000; z > 1; z /= 10)
	{
		if (_abs_ / z)
		{
			__putchar('0' + current / z);
			count++;
		}
		current %= z;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - transform function, a replica of itoa
 * @num: integer
 * @base: core
 * @flags: command-line flags
 *
 * Return: charachter sequence
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - char replace of '#' with '\0'
 * @buf: pointer to the string to modify
 *
 * Return: continuously 0;
 */
void remove_comments(char *buf)
{
	int A;

	for (A = 0; buf[A] != '\0'; A++)
		if (buf[A] == '#' && (!A || buf[A - 1] == ' '))
		{
			buf[A] = '\0';
			break;
		}
}
