#include "main.h"

/**
 * info_cp - copies information
 * @name: name
 * @value: value
 * Return: new environment or alias.
 */
char *info_cp(char *name, char *value)
{
	char *newPtr;
	int nameLength, valueLength, length;

	nameLength = _strlen(name);
	valueLength = _strlen(value);
	length = nameLength + valueLength + 2;
	newPtr = malloc(sizeof(char) * (length));
	_strcpy(newPtr, name);
	_strcat(newPtr, "=");
	_strcat(newPtr, value);
	_strcat(newPtr, "\0");
	return (newPtr);
}

/**
 * environ_set - sets an environment variable
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @datash: shell info
 * Return: Non
 */
void environ_set(char *name, char *value, data_shell *datash)
{
	int i;
	char *varEnviron, *nameEnviron;

	for (i = 0; datash->_environ[i]; i++)
	{
		varEnviron = _strdup(datash->_environ[i]);
		nameEnviron = _strtok(varEnviron, "=");
		if (_strcmp(nameEnviron, name) == 0)
		{
			free(datash->_environ[i]);
			datash->_environ[i] = info_cp(nameEnviron, value);
			free(varEnviron);
			return;
		}
		free(varEnviron);
	}
	datash->_environ = _reallocdp(datash->_environ, i, sizeof(char *) * (i + 2));
	datash->_environ[i] = info_cp(name, value);
	datash->_environ[i + 1] = NULL;
}

/**
 * _setenv - sets environment variables
 * @datash: shell info
 * Return: 1
 */
int _setenv(data_shell *datash)
{
	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		err_get(datash, -1);
		return (1);
	}
	environ_set(datash->args[1], datash->args[2], datash);
	return (1);
}

/**
 * _unsetenv - deletes environment variable
 * @datash: shell info
 * Return: 1
 */
int _unsetenv(data_shell *datash)
{
	char **reallocEnviron;
	char *varEnviron, *nameEnviron;
	int i, j, a;
	if (datash->args[1] == NULL)
	{
		err_get(datash, -1);
		return (1);
	}
	a = -1;
	for (i = 0; datash->_environ[i]; i++)
	{
		varEnviron = _strdup(datash->_environ[i]);
		nameEnviron = _strtok(varEnviron, "=");
		if (_strcmp(nameEnviron, datash->args[1]) == 0)
			a = i;
		free(varEnviron);
	}
	if (a == -1)
	{
		err_get(datash, -1);
		return (1);
	}
	reallocEnviron = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->_environ[i]; i++)
	{
		if (i != a)
		{
			reallocEnviron[j] = datash->_environ[i];
			j++;
		}
	}
	reallocEnviron[j] = NULL;
	free(datash->_environ[a]);
	free(datash->_environ);
	datash->_environ = reallocEnviron;
	return (1);
}
