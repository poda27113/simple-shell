#include "main.h"

/**
 *  * get_builtin - builtin that pais the command in the arg
 *   * @cmd: command
 *    * Return: function pointer of the builtin command
 *     */
int (*get_builtin(char *cmd))(info_t *)
{
		builtin_table builtin[] = {
					{ "myenv", _myenv },
							{ "setenv", _setenv },
									{ "unsetenv", _unsetenv },
											{ "cd", _tell },
													{ "help", _myhelp },
															{ NULL, NULL }
						};
			int i;

			    for (i = 0; builtin[i].type != NULL; i++)
				        {
						        if (_strcmp(builtin[i].type, cmd) == 0)
								            break;
							    }

			        return (builtin[i].func);
}
