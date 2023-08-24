#include "shell.h"

/**
 **_strncpy - string duplication
 *@dest: target string
 *@src: the input string
 *@n: the length of the substring
 *Return: the joined string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int Z, X;
	char *s = dest;

	Z = 0;
	while (src[Z] != '\0' && Z < n - 1)
	{
		dest[Z] = src[Z];
		Z++;
	}
	if (Z < n)
	{
		X = Z;
		while (X < n)
		{
			dest[X] = '\0';
			X++;
		}
	}
	return (s);
}

/**
 **_strncat - appends two strings
 *@dest: the primary string
 *@src: alternative string
 *@n: maximum byte allocation
 *Return: the joined string
 */
char *_strncat(char *dest, char *src, int n)
{
	int Z, X;
	char *s = dest;

	Z = 0;
	X = 0;
	while (dest[Z] != '\0')
		Z++;
	while (src[X] != '\0' && X < n)
	{
		dest[Z] = src[X];
		Z++;
		X++;
	}
	if (X < n)
		dest[Z] = '\0';
	return (s);
}

/**
 **_strchr - finding the position of a charachter
 *@s: string input
 *@c: the search pattern
 *Return: (s) a reference to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
