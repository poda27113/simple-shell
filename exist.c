#include "main.h"

/*
 * The exit_shell function now takes a data_shell struct as its argument.
 * This struct contains the data relevant to the shell, such as the status and arguments.
 * The main function now initializes a data_shell struct and passes it to the hsh function.
 * The hsh function now returns -2 if the exit command is called with one argument.
 * This indicates that the shell should exit with the specified status.
 */


int exit_shell(data_shell *datash)
{
		int status;

			if (datash->args[1] != NULL)
					{
								status = atoi(datash->args[1]);
									}
				else
						{
									status = 0;
										}

					free_datashell(datash);

						return (status);
}

int main(int arg, char **argv)
{
		data_shell datash = DATASH_INIT;
			int ret;

				datash.environ = environ;

					while (1)
							{
										ret = hsh(&datash, argv);
												if (ret == -2)
															{
																			exit(datash);
																					}
													}

						return (0);
}
