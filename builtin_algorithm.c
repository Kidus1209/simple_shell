#include "shell.h"

/**
 * _myhistory - renders the log record, single-line command, numbered,
 *		zero-based indexing
 * @info: parameter list, Used to manage
 *        function declaration
 *  Return: continuously 0
*/

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - assigns an alias to a string
 * @info: argument structure
 * @str: the identifier
 *
 * Return: continuously 0 on success, 1 on defect
*/

int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int retur;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	retur = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (retur);
}

/**
 * set_alias - assigning a string to a variable
 * @info: argument object
 * @str: the text alias
 *
 * Return: continuously 0 on success, 1 on bug
*/

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - outputs an alias string
 *
 * @node: the alias vertex
 *
 * Return: continuously 0 on success, 1 on bug
*/

int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		{
			_putchar(*a);
			_putchar('\'');
			_puts(p + 1);
			_puts("'\n");
		}
		return (0);
	}
	return (1);
}

/**
 * _myalias - emulates the alias functionality (man alias)
 * @info: parameters object, Used to manage
 *          function declaration
 *  Return: continuously 0
*/

int _myalias(info_t *info)
{
	int N = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (N = 1; info->argv[N]; N++)
	{
		p = _strchr(info->argv[N], '=');
		if (p)
			set_alias(info, info->argv[N]);
		else
			print_alias(node_starts_with(info->alias, info->argv[Z], '='));
	}

	return (0);
}
