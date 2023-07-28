#include "main.h"

/**
 *  * no_comment - deletes comments from the path
 *   *
 *    * @in: path string
 *     * Return: path without comments
 *      */
char *no_comment(char *in)
{
		int i, up_to;

			up_to = 0;
				for (i = 0; in[i]; i++)
						{
									if (in[i] == '#')
												{
																if (i == 0)
																				{
																									free(in);
																													return (NULL);
																																}

																			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
																								up_to = i;
																					}
										}

					if (up_to != 0)
							{
										in = _realloc(in, i, up_to + 1);
												in[up_to] = '\0';
													}

						return (in);
}

/**
 *  * shell_lop - Lop of shell
 *   * @info_t: info relevant (av, path, arg)
 *    *
 *     * Return: no return.
 *      */
void shell_lop(info_t *info)
{
		int lop, i_eof;
			char *path;

				lop = 1;
					while (lop == 1)
							{
										write(STDIN_FILENO, "^-^ ", 4);
											 i_eof = read_link(path);
														if (i_eof != -1)
																	{
																					path = without_comment(path);
																								if (path == NULL)
																													continue;

																											if (check_syntax_error(info, path) == 1)
																															{
																																				info->status = 2;
																																								free(path);
																																												continue;
																																															}
																														path = rep_var(path, info);
																																	lop = split_commands(info, path);
													info->status += 1;
																																							free(path);
																																									}
																else
																			{
																							lop = 0;
																										free(path);
																												}
																	}
}
