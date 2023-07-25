#include "main.h"

/*
 * The _strtok() function returns a pointer to the first token in the string.
 * The next call to the _strtok() function will return a pointer to the next token, and so on.
 * The _strtok() function will return NULL when it reaches the end of the string
 * or when it encounters a delimiter that is not in the string.
 * */

char **strtow(char *str, char *delim)
{
	    int i, j, k, m, numwords = 0;
	        char **s;

		    if (str == NULL || str[0] == 0)
			            return (NULL);
		        if (!delim)
				        delim = " ";
			    for (i = 0; str[i] != '\0'; i++)
				            if (!is_delim(str[i], delim) && (is_delim(str[i + 1], delim) || !str[i + 1]))
						                numwords++;

			        if (numwords == 0)
					        return (NULL);
				    s = malloc((1 + numwords) * sizeof(char *));
				        if (!s)
						        return (NULL);
					    for (i = 0, j = 0; j < numwords; j++)
						        {
								        while (is_delim(str[i], delim))
										            i++;
									        k = 0;
										        while (!is_delim(str[i + k], delim) && str[i + k])
												            k++;
											        s[j] = malloc((k + 1) * sizeof(char));
												        if (!s[j])
														        {
																            for (k = 0; k < j; k++)
																		                    free(s[k]);
																	                free(s);
																			            return (NULL);
																				            }
													        for (m = 0; m < k; m++)
															            s[j][m] = str[i++];
														        s[j][m] = 0;
															    }
					        s[j] = NULL;
						    return (s);
}
