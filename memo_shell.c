#include "shell.h"

/**
 * smart_alloc - Reserve memory space if available
 * and register it for future deallocation.
 *
 * @size: The size of memory space to allocate.
 *
 * Return: A pointer to the allocated memory space.
 */

void *smart_alloc(size_t size)
{
	void *pointer;

	pointer = malloc(size);
	if (pointer == NULL)
	{
		_puts("We used up all the memory!!! Holy shit\n");
		exit(20);
	}
	return (pointer);
}

/**
 * free_array - Deallocates a pointer array containing strings.
 *
 * @array: The two-dimensional array of strings.
 *
 * Return: Void.
 */

void free_array(char **array)
{
	free(array[0]);
	free(array);
}

