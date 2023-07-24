#include "shell.h"

/**
 * Function: int is_cmd(info_t *info, char *path)
 * info: A pointer to a structure of type 'info_t' (not used in the function).
 * path: A pointer to a character array representing the file path to be checked.
 * - Returns 1 if the 'path' points to a regular file.
 *   - Returns 0 otherwise.
 *   */

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
 * char *dup_chars(char *pathstr, int start, int stop)
 * - pathstr: A pointer to a character array containing the source string.
 *   - start: The starting index from which characters should be duplicated (inclusive).
 *   - stop: The ending index up to which characters should be duplicated (exclusive).
 *   - Returns a pointer to the static buffer 'buf' containing the duplicated characters.
 *   */

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;
	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * char *find_path(info_t *info, char *pathstr, char *cmd)
 *  - info: A pointer to a structure of type 'info_t' (not used in the function).
 *  - pathstr: A pointer to a character array containing the colon-separated search path.
 *  - cmd: A pointer to a character array representing the command to be found.
 *  If the command is found in any of the colon-separated paths, the function returns a pointer
 *  to the full path of the command.
 *  - If the command is not found, the function returns NULL.
 *  */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
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
	if (!pathstr[i] || pathstr[i] == ':')
{
	path = dup_chars(pathstr, curr_pos, i);
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
	curr_pos = i;
}
	i++;
}
	return (NULL);
}
