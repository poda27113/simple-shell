#include "main.h"
/**
 * The code defines a function `int bfree(void **ptr)` that takes a double pointer as an argument.
 * The function checks if the pointer `ptr` is not NULL and if the value it points to (`*ptr`) is also not NULL.
 * If both conditions are met, it frees the memory pointed to by `*ptr` using the `free()` function.
 * It then sets the value of `*ptr` to NULL to avoid any potential dangling pointer issues.
 * The function returns 1 if memory was freed successfully, and 0 if either `ptr` or `*ptr` is NULL, indicating that no memory was freed.
 * */

int bfree(void **ptr)
{
	if (ptr && *ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (1);
}
	return (0);
}
