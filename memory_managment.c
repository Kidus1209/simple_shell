#include "shell.h"

/**
 * bfree - deallocates the memory and sets the pointer to Null
 * @ptr: pointer deallocation
 *
 * Return: 1 if released. else 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
