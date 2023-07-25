#include "main.h"

/*
 * The _myexit function now checks for the number of arguments and exits with the specified status if there is more than one argument.
 * The main function now calls the hsh function repeatedly until the user exits.
 * The hsh function now calls the find_builtin function first to see if the user entered a built-in command.
 * If the command is not a built-in, the find_cmd function is called to execute the command.
 * The find_builtin function now returns -2 if the command does not exist.
 * The write_history function is now called to write the history to a file when the shell exits.
 */

int _myexit(info_t *info)
{
	    int status;

	        if (info->argc > 1)
			    {
				            status = atoi(info->argv[1]);
					        }
		    else
			        {
					        status = 0;
						    }

		        printf("Exiting with status: %d\n", status);
			    exit(status);

			        return 0;
}

	int ma(char **argv)
{
	    info_t info = INFO_INIT;
	        int ret;

		    info.environ = environ;

		        while (1)
				    {
					            ret = hsh(&info, argv);
						            if (ret == -2)
								            {
										                exit(info.err_num);
												        }
							        }

			    return 0;
}



	int hsh(info_t *info, char **argv)
{
	    ssize_t r = 0;
	        int builtin_ret = 0;

		    while (r != -1 && builtin_ret != -2)
			        {
					        clear_info(info);
						        if (interactive(info))
								            _puts("$ ");
							        _eputchar(BUF_FLUSH);
								        r = get_input(info);
									        if (r != -1)
											        {
													            set_info(info, argv);
														                builtin_ret = find_builtin(info);
																            if (builtin_ret == -1)
																		                    find_cmd(info);
																	            }
										        else if (interactive(info))
												            _putchar('\n');
											        free_info(info, 0);
												    }
		        write_history(info);
			    free_info(info, 1);
			        if (!interactive(info) && info->status)
					        exit(info->status);
				    if (builtin_ret == -2)
					        {
							        if (info->err_num == -1)
									            exit(info->status);
								        exit(info->err_num);
									    }
				        return (builtin_ret);
}
