#include "main.h"

/**
 * strcat_cd - a function that combines the details for a cd error message
 * @datash: relevant data.
 * @msg: message to be printed.
 * @error: output message.
 * @ver_str: line counter.
 * Return: printed error message.
 */
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illeg_flag;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		illeg_flag = malloc(3);
		illeg_flag[0] = '-';
		illeg_flag[1] = datash->args[1][1];
		illeg_flag[2] = '\0';
		_strcat(error, illeg_flag);
		free(illeg_flag);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - the error message associated with the cd command in the get_cd function.
 * @datash: relevant data.
 * Return: the printed error message.
 */
char *error_get_cd(data_shell *datash)
{
	int len, len_id;
	char *err, *ver_str, *msg;

	ver_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(datash->args[1]);
	}

	len = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	len += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	err = malloc(sizeof(char) * (len + 1));

	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}

	err = strcat_cd(datash, msg, err, ver_str);

	free(ver_str);

	return (err);
}

/**
 * error_not_found - a generic error message for a command not found scenario.
 * @datash: relevant data (counter, arguments).
 * Return: the printed error message.
 */
char *error_not_found(data_shell *datash)
{
	int len;
	char *err;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + 16;
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
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(ver_str);
	return (err);
}

/**
 * error_exit_shell - a generic error message for the exit command in the get_exit function.
 * @datash: relevant data (counter, arguments).
 * Return: the printed error message.
 */
char *error_exit_shell(data_shell *datash)
{
	int len;
	char *err;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(ver_str);
	len += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_str);
	_strcat(err, ": ");
	_strcat(err, datash->args[0]);
	_strcat(err, ": Illegal number: ");
	_strcat(err, datash->args[1]);
	_strcat(err, "\n\0");
	free(ver_str);

	return (err);
}
