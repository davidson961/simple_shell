#include "main.h"

/**
 * shell_exit - exits shell
 * @datash: shell info
 * Return: 0 or 1
 */
int shell_exit(data_shell *datash)
{
	unsigned int status;
	int check_digit, str_length, big_num;

	if (datash->args[1] != NULL)
	{
		status = _atoi(datash->args[1]);
		check_digit = _isdigit(datash->args[1]);
		str_length = _strlen(datash->args[1]);
		big_num = status > (unsigned int)INT_MAX;
		if (!check_digit || str_length > 10 || big_num)
		{
			err_get(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (status % 256);
	}
	return (0);
}

/**
 * handle_sigint - ctrl+c functionality
 * @sig: signal handler
 */
void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n--> ", 5);
}
