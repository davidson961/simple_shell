#include "main.h"

/**
 * _strcat - this joins strings
 * @dest: first string
 * @src: second string
 * Return: the two stringd
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int m;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (m = 0; src[m] != '\0'; m++)
	{
		dest[i] = src[m];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * *_strcpy - this copies string
 * @dest: first string
 * @src: seconnd string
 * Return: the destination
 */
char *_strcpy(char *dest, char *src)
{

	size_t g;

	for (g = 0; src[g] != '\0'; g++)
		dest[g] = src[g];
	dest[g] = '\0';
	return (dest);
}
/**
 * _strcmp - this compares two strings.
 * @s1: 1st string
 * @s2: 2nd string
 * Return: 0, 1 or -1
 */
int _strcmp(char *s1, char *s2)
{
	int p;

	for (p = 0; s1[p] == s2[p] && s1[p]; p++)
		;
	if (s1[p] > s2[p])
		return (1);
	if (s1[p] < s2[p])
		return (-1);
	return (0);
}
/**
 * _strchr - this searches for a char
 * @s: the string
 * @c: the character
 * Return: occcurence of char
 */
char *_strchr(char *s, char c)
{
	unsigned int k = 0;

	for (; *(s + k) != '\0'; k++)
		if (*(s + k) == c)
			return (s + k);
	if (*(s + k) == c)
		return (s + k);
	return ('\0');
}
/**
 * _strspn - the length of substring.
 * @s: init segment.
 * @accept: allowed bytes.
 * Return: number of allowed bytes.
 */
int _strspn(char *s, char *accept)
{
	int i, t, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (t = 0; *(accept + t) != '\0'; t++)
		{
			if (*(s + i) == *(accept + t))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}

	return (i);
}
