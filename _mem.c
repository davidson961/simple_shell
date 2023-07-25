#include "main.h"

/**
 * _memcpy - Copies information from one pointer to another.
 * @dest: Destination pointer.
 * @src: Source pointer.
 * @size: Size of the destination.
 * Return: None.
 */
void _memcpy(void *dest, const void *src, unsigned int size)
{
    char *_src = (char *)src;
    char *_dest = (char *)dest;
    unsigned int i;

    for (i = 0; i < size; i++)
    {
        _dest[i] = _src[i];
    }
}

/**
 * _realloc - Reallocates memory with the new size.
 * @ptr: Initial memory.
 * @old_size: Old size of memory.
 * @new_size: New size of memory.
 * Return: Pointer to the relevant memory.
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
 * _reallocdp - Reallocates memory for double pointers.
 * @ptr: Initial memory.
 * @old_size: Old size of memory.
 * @new_size: New size of memory.
 * Return: Pointer to the relevant memory.
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
