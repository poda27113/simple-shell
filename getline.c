#include "main.h"

ssize_t get_input(info_t *info)
{
		static char *buf = NULL;
			static size_t i = 0;
				size_t len;
					ssize_t r;

						if (!buf)
								{
											buf = malloc(sizeof(char) * READ_BUF_SIZE);
													if (!buf)
																	return -1;
														}

							len = READ_BUF_SIZE - i;
								r = read(info->readfd, buf + i, len);
									if (r == -1)
												return -1;
										if (r == 0)
													return -1;

											i += r;
												if (buf[i - 1] == '\n')
															return i;

													return -1;
}
