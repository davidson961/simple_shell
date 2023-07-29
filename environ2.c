#include "main.h"

/**
 * info_cp - this copies information
 * @name: this is the name
 * @value: this is the value
 * Return: new environ or alias.
 */
char *info_cp(char *name, char *value)
{
	char *new_ptr;
	int name_l, value_l, length;

	name_l = _strlen(name);
	value_l = _strlen(value);
	length = name_l + value_l + 2;
	new_ptr = malloc(sizeof(char) * (length));
	_strcpy(new_ptr, name);
	_strcat(new_ptr, "=");
	_strcat(new_ptr, value);
	_strcat(new_ptr, "\0");
	return (new_ptr);
}

/**
 * environ_set - this is the sets of an env variable
 * @name: this is the name of the env variable
 * @value: thid id the value of the env variable
 * @datash: the shell info
 * Return: Non
 */
void environ_set(char *name, char *value, data_shell *datash)
{
	int u;
	char *var_environ, *name_environ;

	for (u = 0; datash->_environ[u]; u++)
	{
		var_environ = _strdup(datash->_environ[u]);
		name_environ = _strtok(var_environ, "=");
		if (_strcmp(name_environ, name) == 0)
		{
			free(datash->_environ[u]);
			datash->_environ[u] = info_cp(name_environ, value);
			free(var_environ);
			return;
		}
		free(var_environ);
	}
	datash->_environ = _reallocdp(datash->_environ, u, sizeof(char *) * (u + 2));
	datash->_environ[i] = info_cp(name, value);
	datash->_environ[u + 1] = NULL;
}

/**
 * _setenv - compares env variables
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
 * _unsetenv - this deletes env variable
 * @datash: the shell info
 * Return: 1
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_environ, *name_environ;
	int u, j, a;
	if (datash->args[1] == NULL)
	{
		err_get(datash, -1);
		return (1);
	}
	a = -1;
	for (u = 0; datash->_environ[u]; u++)
	{
		var_environ = _strdup(datash->_environ[u]);
		name_environ = _strtok(var_environ, "=");
		if (_strcmp(name_environ, datash->args[1]) == 0)
			a = u;
		free(var_environ);
	}
	if (a == -1)
	{
		err_get(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (u));
	for (u = j = 0; datash->_environ[u]; u++)
	{
		if (u != a)
		{
			realloc_environ[j] = datash->_environ[u];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datash->_environ[a]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}
