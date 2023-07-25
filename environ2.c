#include "main.h"

int _setenv(int *info, char *var, char *value)
{
		struct env_list *node, *new_node;

			if (!var || !value)
						return (0);

					struct env_list env;

						struct (node) = info->env;

							while (node)
									{
												if (strcmp(node->next, var) == 0)
															{
																			free(node->next);
																						node->next = strdup(var);
																									node->next = strcat(node->next, "=");
																												node->next = strcat(node->next, value);
																															return (0);
																																	}
														node = node->next;
															}

								new_node = malloc(sizeof(list_t));
								new_node->next = malloc(strlen(var) + strlen("=") + strlen(value) + 1); /* Allocate memory for concatenated string*/
								strcpy(new_node->next, var); /* Copy 'var' to 'new_node->next'*/
								strcat(new_node->next, "="); /* Concatenate "=" to 'new_node->next'*/
								strcat(new_node->next, value); /* Concatenate 'value' to 'new_node->next'*/
								new_node->next = info->env;
								info->env = new_node;
								return (0);

}
