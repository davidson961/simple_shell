#include "main.h"

/**
 * remove_comment - this removes the comments
 *
 * @in: the input
 * Return: the input without the comments
 */
char *remove_comment(char *in)
{
	int k, position;

	position = 0;
	for (k = 0; in[k]; k++)
	{
		if (in[k] == '#')
		{
			if (k == 0)
			{
				free(in);
				return (NULL);
			}
			if (in[k - 1] == ' ' || in[k - 1] == '\t' || in[k - 1] == ';')
				position = k;
		}
	}
	if (position != 0)
	{
		in = _realloc(in, k, position + 1);
		in[position] = '\0';
	}
	return (in);
}

/**
 * loop_shell - Shell loop
 * @datash: shell info
 * Return: no return.
 */
void loop_shell(data_shell *datash)
{
	int lp, i_eof;
	char *inp;

	lp = 1;
	while (lp == 1)
	{
		write(STDIN_FILENO, "--> ", 4);
		inp = _readline(&i_eof);
		if (i_eof != -1)
		{
			inp = remove_comment(inp);
			if (inp == NULL)
				continue;

			if (syntax_err_checker(datash, inp) == 1)
			{
				datash->status = 2;
				free(inp);
				continue;
			}
			inp = replace_var(inp, datash);
			lp = command_split(datash, inp);
			datash->counter += 1;
			free(inp);
		}
		else
		{
			lp = 0;
			free(inp);
		}
	}
}

/**
 * _readline - this reads from input.
 * @i_eof: this return value of getline
 * Return: input in form of a string
 */
char *_readline(int *i_eof)
{
	char *inp = NULL;
	size_t size = 0;

	*i_eof = getline(&inp, &size, stdin);

	return (inp);
}
