#include "main.h"

/**
 * env_err - Generates an error message for environment-related issues.
 * @datash: Data from the current shell.
 * Return: The complete error message.
 */
char *env_err(data_shell *datash)
{
	int lenght;
	char *err;
	char *str_var;
	char *msg;

	str_var = aux_itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	lenght = _strlen(datash->av[0]) + _strlen(str_var);
	lenght += _strlen(datash->args[0]) + _strlen(msg) + 4;
	err = malloc(sizeof(char) * (lenght + 1));
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
	_strcat(err, msg);
	_strcat(err, "\0");
	free(str_var);
	return (err);
}
/**
 * path_denied_err - Generat error msg for perm denied when accessing  path.
 * @datash: Data from the current shell.
 * Return: The complete error message.
 */
char *path_denied_err(data_shell *datash)
{
	int lenght;
	char *str_var, *err;

	str_var = aux_itoa(datash->counter);
	lenght = _strlen(datash->av[0]) + _strlen(str_var);
	lenght += _strlen(datash->args[0]) + 24;
	err = malloc(sizeof(char) * (lenght + 1));
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
