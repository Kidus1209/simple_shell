#include "shell.h"

/**
 * _myexit - terminates the shell
 * @info: argument list
 * unchanging function declaration
 * Return: returns with a specific exit code
 * (0) if info.argv<0> != "return"
 */
int _myexit(info_t *info)
{
	int terminationcondition;

	if (info->argv[1]) /* If there is an exit arguments */
	{
		terminationcondition = _erratoi(info->argv[1]);
		if (terminationcondition == -1)
		{
			info->status = 2;
			print_error(info, "NaN: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - "chdir"
 * @info: Syntax containing capacity parameters & it's Used to manage
 * function declaration
 * Return: continuously 0
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int cd_return;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			cd_return = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			cd_return = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		cd_return = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		cd_return = chdir(info->argv[1]);
	if (cd_return == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - sets the current working directory
 * @info: parameter list, it's Used to manage
 * function declaration
 * Return: continuously 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
