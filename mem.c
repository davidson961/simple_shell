#include "main.h"

/**
 * _memcpy - This copies info from one pointer to another.
 * @newptr: the destination .
 * @ptr: the source .
 * @size: size of the destination.
 * Return: Non.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *_ptr = (char *)ptr;
	char *_newptr = (char *)newptr;
	unsigned int m;

	for (m = 0; m < size; m++)
    {
		_newptr[m] = _ptr[m];
	}
}

/**
 * _realloc - this reallocates memory with the new size.
 * @ptr: the initial memory
 * @old_size: the old size of memory
 * @new_size: the new size of memory
 * Return: ptr of the relevant mem.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (new_size < old_size)
		_memcpy(new_ptr, ptr, new_size);
	else
		_memcpy(new_ptr, ptr, old_size);

	free(ptr);
	return (new_ptr);
}

/**
 * _reallocdp - this reallocates a memory of double pointers.
 * @ptr: the initial memory
 * @old_size: the old size of memory
 * @new_size: the new size of memory
 * Return: ptr of the relevant mem.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **new_ptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));
	if (new_size == old_size)
		return (ptr);
	new_ptr = malloc(sizeof(char *) * new_size);
	if (new_ptr == NULL)
		return (NULL);
	for (i = 0; i < old_size; i++)
    {
        new_ptr[i] = ptr[i];
    }
	free(ptr);
	return (new_ptr);
}
