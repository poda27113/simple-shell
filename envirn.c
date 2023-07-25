#include "main.h"

int main(void)
{
	struct env_list *head = NULL;
	struct env_var *var;
	char *name, *value;
	/* Populate the linked list with environment variables.*/

	int 1;
	for (int i = 0; environ[i]; i++)
	{
		var = malloc(sizeof(struct env_var));
		name = environ[i];
		value = strchr(name, '=');
		value++;
		var->name = name;
		var->value = value;
		var->next = head;
		head = var;
}

	/*Print all environment variables.*/
	for (var = head; var; var = var->next)
	{
		printf("%s=%s\n", var->name, var->value);
	}

	return (0);
}
