#include "main.h"
/**
 * rev_string - this reverses a string.
 * @s: the string.
 * Return: Non
 */
void rev_string(char *s)
{
	int counter = 0;
	int i, f;
	char *_str, tem;

	while (counter >= 0)
	{
		if (s[counter] == '\0')
			break;
		counter++;
	}
	_str = s;
	for (i = 0; i < (counter - 1); i++)
	{
		for (f = i + 1; f > 0; f--)
		{
			tem = *(_str + f);
			*(_str + f) = *(_str + (f - 1));
			*(_str + (f - 1)) = tem;
		}
	}
}
