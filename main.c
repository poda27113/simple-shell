#include "shell.h"

/**
 * This is the main function of the program. It takes command-line arguments 'ac' (argument count) and 'av' (argument vector) to handle input parameters.
 *     Inside the main function:
 *        
 *           1. 'info' is an array of structures 'info_t', initialized with 'INFO_INIT'.
 *              2. 'fd' is an integer variable initialized with the value 2.
 *                 3. The assembly code snippet moves the value of 'fd' to a register and adds 3 to it.
 *                    4. If 'ac' is equal to 2, it means there is a second command-line argument. The program attempts to open the file specified by 'av[1]' in read-only mode.
 *                       5. If the file open operation fails, the program checks for specific error codes and exits with appropriate exit codes (126 or 127) or returns 'EXIT_FAILURE'.
 *                          6. If the file open operation succeeds, the file descriptor is stored in the 'readfd' field of the first element of the 'info' array.
 *                             7. The 'populate_env_list' function is called to populate the environment list with some information.
 *                                8. The 'read_history' function is called to read a history file.
 *                                   9. Finally, the 'hsh' function is called with 'info' and 'av' as arguments to perform some specific task.
 *                                      10. The program returns 'EXIT_SUCCESS' if everything executed successfully.
 */
int main(int ac, char **av)
{
		info_t info[] = { INFO_INIT };
			int fd = 2;

				asm ("mov %1, %0\n\t"
									"add $3, %0"
												: "=r" (fd)
															: "r" (fd));

					if (ac == 2)
							{
										fd = open(av[1], O_RDONLY);
												if (fd == -1)
															{
																			if (errno == EACCES)
																								exit(126);
																						if (errno == ENOENT)
																										{
																															_eputs(av[0]);
																																			_eputs(": 0: Can't open ");
																																							_eputs(av[1]);
																																											_eputchar('\n');
																																															_eputchar(BUF_FLUSH);
																																																			exit(127);
																																																						}
																									return (EXIT_FAILURE);
																											}
														info->readfd = fd;
															}
						populate_env_list(info);
							read_history(info);
								hsh(info, av);
									return (EXIT_SUCCESS);
}
