#include "main.h"

/**
 * str_dup - function to duplicate string
 * @s: Char pointer of the string.
 * Return: new String pointer.
 */
char *str_dup(const char *s)
{
	char *n;
	size_t length;

	length = str_len(s);
	n = malloc(sizeof(char) * (length + 1));
	if (n == NULL)
		return (NULL);
	_memcpy(n, s, length + 1);
	return (n);
}

/**
 * str_len - string length
 * @s: string pointer
 * Return: length
 */
int str_len(const char *s)
{
	int length;

	for (length = 0; s[length] != 0; length++)
	{
	}
	return (length);
}

/**
 * compare_chars - compares two strings
 * @str: the string
 * @delim: the delimiters
 * Return: 1 or 0
 */
int compare_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * str_tok - splits the string by the delimiter
 * @str: the string.
 * @delim: the delimiter.
 * Return: splitted string
 */
char *str_tok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_begin;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (compare_chars(str, delim))
			return (NULL);
		splitted = str;
		i = str_len(str);
		str_end = &str[i];
	}
	str_begin = splitted;
	if (str_begin == str_end)
		return (NULL);
	for (bool = 0; *splitted; splitted++)
	{
		if (splitted != str_begin)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_begin)
					str_begin++;
				break;
			}
		}
		if (bool == 0 && *splitted)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_begin);
}

/**
 * is_digit - checks for numbers
 * @s: string
 * Return: 1 or 0
 */
int is_digit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
