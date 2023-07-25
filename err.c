#include "main.h"

/**
 *  * _eputs - prints an input string to stderr
 *   * @str: the string to be printed
 *    *
 *     * Return: Nothing
 *      */
void _eputs(char *str)
{
	    int i = 0;

	        if (!str)
			        return;
		    while (str[i] != '\0')
			        {
					        _eputchar(str[i]);
						        i++;
							    }
}

/**
 *  * _eputchar - writes the character c to stderr
 *   * @c: The character to print
 *    *
 *     * Return: On success 1.
 *      * On error, -1 is returned, and errno is set appropriately.
 *       */
int _eputchar(char c)
{
	    static int i;
	        static char buf[WRITE_BUF_SIZE];

		    if (c == '\n' || i >= WRITE_BUF_SIZE)
			        {
					        write(2, buf, i);
						        i = 0;
							    }
		        if (c != '\n')
				        buf[i++] = c;
			    return 1;
}

/**
 *  * _putfd - writes the character c to given fd
 *   * @c: The character to print
 *    * @fd: The filedescriptor to write to
 *     *
 *      * Return: On success 1.
 *       * On error, -1 is returned, and errno is set appropriately.
 *        */
int _putfd(char c, int fd)
{
	    static int i;
	        static char buf[WRITE_BUF_SIZE];

		    if (c == '\n' || i >= WRITE_BUF_SIZE)
			        {
					        write(fd, buf, i);
						        i = 0;
							    }
		        if (c != '\n')
				        buf[i++] = c;
			    return 1;
}

/**
 *  * _putsfd - prints an input string to a given file descriptor
 *   * @str: the string to be printed
 *    * @fd: the file descriptor to write to
 *     *
 *      * Return: the number of characters put
 *       */
int _putsfd(char *str, int fd)
{
	    int i = 0;

	        if (!str)
			        return 0;
		    while (*str)
			        {
					        i += _putfd(*str++, fd);
						    }
		        return i;
}

/**
 *  * error_env - error message for env in get_env.
 *   * @datash: data relevant (counter, arguments)
 *    * Return: error message (a dynamically allocated string).
 *     */
char *error_env(info_t *info)
{
	    int length;
	        char *error;
		    char *ver_str;
		        char *msg = ": Unable to add/remove from environment\n";

			    ver_str = aux_itoa(info->line_count);
			        length = strlen(info->argv[0]) + strlen(ver_str) + strlen(info->arg[0]) + strlen(msg);
				    error = malloc(sizeof(char) * (length + 1));
				        if (error == NULL)
						    {
							            free(ver_str);
								            return NULL;
									        }

					    sprintf(error, "%s: %s: %d%s", info->argv[0], ver_str, info->arg[0], msg);
					        free(ver_str);

						    return error;
}

/**
 *  * error_path_126 - error message for path and failure denied permission.
 *   * @datash: data relevant (counter, arguments).
 *    *
 *     * Return: The error string (a dynamically allocated string).
 *      */
char *error_path_126(info_t *info)
{
	    int length;
	        char *error;
		    char *ver_str;

		        ver_str = aux_itoa(info->line_count);
			    length = strlen(info->argv[0]) + strlen(ver_str) + strlen(info->arg[0]) + 24;
			        error = malloc(sizeof(char) * (length + 1));
				    if (error == NULL)
					        {
							        free(ver_str);
								        return NULL;
									    }

				        sprintf(error, "%s: %s: %d: Permission denied\n", info->argv[0], ver_str, info->arg[0]);
					    free(ver_str);

					        return error;
}
