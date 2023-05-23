#include "shell.h"

/**
 * _realloc - reallocates previously allocated memory
 * @ptr: pointer to memory
 * @old_size: old memory size
 * @new_size: new memory size
 *
 * Return: reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}
	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(old_size + (new_size - old_size));

	memcpy(new_ptr, ptr, old_size);

	free(ptr);

	return (new_ptr);
}
