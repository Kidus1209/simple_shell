#include "shell.h"

/**
 * is_cmd - checks the file executability
 * @info: information structure
 * @path: file directory
 *
 * Return: 1 if boolean true, 0 else
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - character repetiton
 * @pathstr: directory location
 * @start: offset index
 * @stop: end index
 *
 * Return: buffer pointer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int L = 0, H = 0;

	for (H = 0, L = start; L < stop; L++)
		if (pathstr[i] != ':')
			buf[H++] = pathstr[L];
	buf[H] = 0;
	return (buf);
}

/**
 * find_path - locates this command in the PATH string
 * @info: information structure
 * @pathstr: file/directory location
 * @cmd: the command to locate
 *
 * Return: complete path of the command if it exists,
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int L = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[L] || pathstr[L] == ':')
		{
			path = dup_chars(pathstr, curr_pos, L);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = L;
		}
		L++;
	}
	return (NULL);
}
