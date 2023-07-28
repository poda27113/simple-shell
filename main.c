#include "main.h"

/* Function prototype for shell_loop*/
void shell_loop(info_t *info);

/**
 *  * get_sigint - Handle the ctrl + c call in the prompt
 *   * @sig: Signal handler
 *    */
void get_sigint(int sig)
{
	    (void)sig; /* Unused parameter*/
	        write(STDOUT_FILENO, "\n^-^ ", 5);
}


/**
 *  * free_data - frees data structure
 *   *
 *    * @info: data structure
 *     * Return: no return
 *      */
void free_data(info_t *info)
{
	    unsigned int i;

	        for (i = 0; info->environ[i]; i++)
			    {
				            free(info->environ[i]);
					        }

		    free(info->environ);
}

/**
 *  * set_data - Initialize data structure
 *   *
 *    * @info: data structure
 *     * @av: argument vector
 *      * Return: no return
 *       */
void set_data(info_t *info, char **av)
{
	    unsigned int i;

	        info->argv = av;
		    info->arg = NULL;
		        info->path = NULL;
			    info->argc = 0;
			        info->line_count = 0;
				    info->err_num = 0;
				        info->linecount_flag = 0;
					    info->fname = NULL;
					        info->env = NULL;
						    info->history = NULL;
						        info->alias = NULL;
							    info->environ = get_environ(info);
							        info->env_changed = 0;
								    info->status = 0;

								        for (i = 0; info->environ[i]; i++)
										        ;

									    info->environ = malloc(sizeof(char *) * (i + 1));

									        for (i = 0; info->environ[i]; i++)
											    {
												            info->environ[i] = _strdup(info->environ[i]);
													        }

										    info->environ[i] = NULL;
										        info->histcount = 0;
}

/**
 *  * main - Entry point
 *   *
 *    * @ac: argument count
 *     * @av: argument vector
 *      *
 *       * Return: 0 on success.
 *        */

int main(int ac, char **av)
{
	    info_t info = INFO_INIT;
	        (void) ac;

		    signal(SIGINT, get_sigint);
		        set_data(&info, av);
			    shell_loop(&info);
			        free_data(&info);
				    if (info.status < 0)
					            return (255);
				        return (info.status);
}
