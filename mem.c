#include "main.h"


void *_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
		char **newptr;
			unsigned int i;

				if (ptr == NULL)
							return (malloc(sizeof(char *) * new_size));

					if (new_size == old_size)
								return (ptr);

						newptr = malloc(sizeof(char *) * new_size);
							if (newptr == NULL)
										return (NULL);

								for (i = 0; i < old_size; i++)
											newptr[i] = ptr[i];

									free(ptr);

										return (newptr);
}
