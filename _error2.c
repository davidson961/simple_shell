#include "main.h"

/**
 * error_env - the error message associated with the env command in the get_env function.
 * @datash: relevant data (counter, arguments).
 * Return: the printed error message.
 */
char *error_env(data_shell *datash)
{
	int len;
	char *err;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + _strlen(msg) + 4;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}

	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, msg);
	_strcat(err, "\0");
	free(ver_str);

	return (err);
}
/**
 * error_path_126 - the error message for issues related to path and permission denial.
 * @datash: relevant data (counter, arguments).
 * Return: The printed error string.
 */
char *error_path_126(data_shell *datash)
{
	int len;
	char *ver_str;
	char *err;

	ver_str = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + 24;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}
