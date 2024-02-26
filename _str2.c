#include "main.h"

/**
 * _strdup -  function replicates a string in heap memory.
 * @s: Char pointer representing the string.
 * Return: Duplicated string.
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - function returns the lenght of a string.
 * @s:The char pointer.
 * Return: Success, Always 0.
 */

int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - function compares characters of strings.
 * @str: the input string.
 * @delim: The delimiter.
 * Return: 1 if they are equal, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int n, m, l;

	for (n = 0, l = 0; str[n]; n++)
	{
		for (m = 0; delim[m]; m++)
		{
			if (str[n] == delim[m])
			{
				l++;
				break;
			}
		}
	}
	if (n == l)
		return (1);
	return (0);
}

/**
 * _strtok - function divides a string using a specified delimiter.
 * @str: the input string.
 * @delim: the delimiter.
 * Return: The split string.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int n, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str;
		n = _strlen(str);
		str_end = &str[n];
	}
	str_start = splitted;
	if (str_start == str_end)
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		for (n = 0; delim[n]; n++)
		{
			if (*splitted == delim[n])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (str_start);
}

/**
 * _isdigit -  function determines if the given string is a number.
 * @s: the input string.
 * Return: 1 if the string is a number, 0 otherwise.
 */
int _isdigit(const char *s)
{
	unsigned int n;

	for (n = 0; s[n]; n++)
	{
		if (s[n] < 48 || s[n] > 57)
			return (0);
	}
	return (1);
}
