#include "shell.h"

/**
 * interactive - it returns truthy if the shell is in interactive mode.
 * @info: structure pointer
 *
 * Return: 1 if repl, 0 else
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - charachter splitting
 * @c: the charachter to inspect
 * @delim: the token string
 * Return: 1 if truthy, 0 if falsy
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - verifies if charachter is alphabetic
 * @c: user input
 * Return: 1 if c is lexical, 0 else
 */

int _isalpha(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - casts a sequence of charachters to an int
 * @s: the source string
 * Return: 0 if no numbers in text, changed integer else
 */

int _atoi(char *s)
{
	int z, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (z = 0; s[z] != '\0' && flag != 2; z++)
	{
		if (s[z] == '-')
			sign *= -1;

		if (s[z] >= '0' && s[z] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[z] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
