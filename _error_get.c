#include "main.h"

/**
 * err_get - executes the error according to the permission, syntax, or builtin
 * @datash: shell info
 * @eval: value of the error
 * Return: err
 */
int err_get(data_shell *datash, int eval)
{
	char *err;

	switch (eval)
	{
	case -1:
		err = envErr(datash);
		break;
	case 126:
		err = pathDeniedErr(datash);
		break;
	case 127:
		err = notFoundErr(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			err = exitShellErr(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			err = getCdErr(datash);
		break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}

	datash->status = eval;
	return (eval);
}
