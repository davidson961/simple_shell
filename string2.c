#include "main.h"
/**
 * _strdup - this is the function to deplicate string
 * @s: this Char pointer of the string.
 * Return: the new String pointer.
 */
char *_strdup(const char *s)
{
	char *n;
	size_t length;

	length = _strlen(s);
	n = malloc(sizeof(char) * (length + 1));
	if (n == NULL)
		return (NULL);
	_memcpy(n, s, length + 1);
	return (n);
}
/**
 * _strlen - the string length
 * @s: the string pointer
 * Return: length
 */
int _strlen(const char *s)
{
	int length;

	for (length = 0; s[length] != 0; length++)
	{
	}
	return (length);
}
/**
 * cmp_chars - this compares two strings
 * @str: the string
 * @delim: the delimiters
 * Return: 1 or 0
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, c, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (c = 0; delim[c]; c++)
		{
			if (str[i] == delim[c])
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
 * _strtok - this splits the string by the delimiter
 * @str:  string.
 * @delim: delimiter.
 * Return: splitted string
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_begin;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str;
		i = _strlen(str);
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
 * _isdigit - this checks for numbers
 * @s: the string
 * Return: 1 or 0
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
