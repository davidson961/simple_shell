#include "main.h"

/**
 * envErr - env error message
 * @datash: data from the current shell
 * Return: Full error message
 */
char *envErr(data_shell *datash)
{
	int len;
	char *err;
	char *str_var;
	char *message;

	str_var = aux_itoa(datash->counter);
	message = ": Unable to add/remove from environment\n";
	len = _strlen(datash->av[0]) + _strlen(str_var);
	len += _strlen(datash->args[0]) + _strlen(message) + 4;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(str_var);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, str_var);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, message);
	_strcat(err, "\0");
	free(str_var);
	return (err);
}

/**
 * pathDeniedErr - path denied error message
 * @datash: data from the current shell
 * Return: Full error message
 */
char *pathDeniedErr(data_shell *datash)
{
	int len;
	char *str_var, *err;

	str_var = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(str_var);
	len += _strlen(datash->args[0]) + 24;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(str_var);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, str_var);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(str_var);
	return (err);
}
