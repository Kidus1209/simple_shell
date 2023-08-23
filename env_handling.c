#include "shell.h"

/**
 * _myenv - outputting the current environment
 * @info: framework containing potential arguments. Used to manage
 *          function declaration
 * Return: continuously 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - retrieves the value of an environment variable
 * @info: framework containing potential arguments. Used to manage
 * @name: environment variable name
 *
 * Return: the variable
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - declare a new environment variable,
 *
 * @info: framework containing potential arguments. Used to manage
 *            function declaration
 *  Return: continuously 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - unset an environment variable
 * @info: framework containing potential arguments. Used to manage
 *        function declaration
 * Return: continuously 0
 */
int _myunsetenv(info_t *info)
{
	int P;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (P = 1; P < info->argc; P++)
		_unsetenv(info, info->argv[P]);

	return (0);
}

/**
 * populate_env_list - initializes environment linked list
 * @info: framework containing potential arguments. Used to manage
 *          function declaration
 * Return: continuously 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

