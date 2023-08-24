#include "shell.h"

/**
 * _eputs - displays an input string
 * @str: the string to be print
 *
 * Return: null
 */
void _eputs(char *str)
{
	int F = 0;

	if (!str)
		return;
	while (str[F] != '\0')
	{
		_eputchar(str[F]);
		F++;
	}
}

/**
 * _eputchar - prints the character c to the standard error stream
 * @c: The output character
 *
 * Return: in success 1.
 * On error, -1 is yielded. and error code is properly set
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - charachter output to file descriptor fd
 * @c: string or text
 * @fd: output stream
 *
 * Return: On success 1.
 * On error, -1 is yielded, and errno is correctly assigned
 */
int _putfd(char c, int fd)
{
	static int F;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || F >= WRITE_BUF_SIZE)
	{
		write(fd, buf, F);
		F = 0;
	}
	if (c != BUF_FLUSH)
		buf[F++] = c;
	return (1);
}

/**
 * _putsfd - dsiplays an input string
 * @str: the output string
 * @fd: the output file
 *
 * Return: length of charachters
 */
int _putsfd(char *str, int fd)
{
	int F = 0;

	if (!str)
		return (0);
	while (*str)
	{
		F += _putfd(*str++, fd);
	}
	return (F);
}
