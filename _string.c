#include "main.h"

/**
 * str_cat - concatenates strings
 * @dest: first string
 * @src: second string
 * Return: the concatenated string
 */
char *str_cat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

/**
 * str_cpy - copies string
 * @dest: destination string
 * @src: source string
 * Return: the destination string
 */
char *str_cpy(char *dest, char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return dest;
}

/**
 * str_cmp - compares two strings.
 * @s1: first string
 * @s2: second string
 * Return: 0, 1 or -1
 */
int str_cmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return 1;
	if (s1[i] < s2[i])
		return -1;
	return 0;
}

/**
 * str_chr - searches for a char
 * @s: string
 * @c: the character
 * Return: occurrence of char
 */
char *str_chr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return '\0';
}

/**
 * str_spn - length of substring.
 * @s: initial segment.
 * @accept: allowed bytes.
 * Return: number of allowed bytes.
 */
int str_spn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}

	return i;
}
