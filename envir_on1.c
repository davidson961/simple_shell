#include "main.h"

/**
 * compareEnvNames - compares environment variables
 * @nenv: name of the environment variable
 * @name: name to compare
 * Return: 0 or the number of characters matched.
 */
int compareEnvNames(const char *nenv, const char *name)
{
	int i;
	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
			return (0);
	}
	return (i + 1);
}

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the environment variable
 * @_environ: array of environment variables
 * Return: value of the environment variable or NULL if not found
 */
char *_getenv(const char *name, char **_environ)
{
	char *envPtr;
	int i;
	int checker = 0;
	envPtr = NULL;

	for (i = 0; _environ[i]; i++)
	{
		checker = compareEnvNames(_environ[i], name);
		if (checker)
		{
			envPtr = _environ[i];
			break;
		}
	}
	return (envPtr + checker);
}

/**
 * envPrinter - prints all environment variables
 * @datash: shell info
 * Return: 1
 */
int envPrinter(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{
		for (j = 0; datash->_environ[i][j]; j++)
			;
		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;
	return (1);
}
