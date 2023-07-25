#include "main.h"

/**
 * changeDir - changes current working directory
 * @datash: data relevant
 * Return: 1 on success
 */
int changeDir(data_shell *datash)
{
	char *dir;
	int home, home2, dash;

	dir = datash->args[1];
	if (dir != NULL)
	{
		home = _strcmp("$HOME", dir);
		home2 = _strcmp("~", dir);
		dash = _strcmp("--", dir);
	}
	if (dir == NULL || !home || !home2 || !dash)
	{
		cdHome(datash);
		return (1);
	}
	if (_strcmp("-", dir) == 0)
	{
		cdPrev(datash);
		return (1);
	}
	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		parCd(datash);
		return (1);
	}
	cdTo(datash);
	return (1);
}
