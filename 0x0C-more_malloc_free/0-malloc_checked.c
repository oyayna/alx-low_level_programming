#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Allocates memory using malloc.
 * @size: The number of bytes to allocate.
 *
 * Return: A pointer to the allocated memory.
 * If malloc fails, the function terminates the program with exit code 98.
 */
void *malloc_checked(unsigned int size)
{
	void *ptr;

	ptr = malloc(size);

	if (ptr == NULL)
		exit(98);

	return (ptr);
}

