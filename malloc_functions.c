#include "monty.h"
/**
 * _calloc - function that connects two strings specially
 * @nmemb: number of elements
 * @size: type of elements
 * Return: nothing
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p = NULL;
	unsigned int k;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(nmemb * size);
	if (p == NULL)
	{
		return (NULL);
	}
		for (k = 0; k < (nmemb * size); k++)
	{
		*((char *)(p) + k) = 0;
	}
	return (p);
}
/**
 * _realloc - function that replaces the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of Bytes
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int k;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (k = 0; k < old_size; k++)
			p[k] = *((char *)ptr + k);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (k = 0; k < new_size; k++)
			p[k] = *((char *)ptr + k);
		free(ptr);
	}
	return (p);
}
