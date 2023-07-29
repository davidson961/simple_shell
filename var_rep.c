#include "main.h"

/**
 * env_checker - This checks if the variable is an env variable
 * @h: the head of list
 * @in: the input
 * @data: the shell info
 * Return: Non.
 */
void env_checker(r_var **ch, char *in, data_shell *data)
{
	int w, ch, i, lval;
	char **_envrn;

	_envrn = data->_environ;
	for (w = 0; _envrn[w]; w++)
	{
<<<<<<< HEAD
		for (i = 1, ch = 0; _envrn[w][ch]; ch++)
=======
		for (i = 1, h = 0; _envrn[w][ch]; h++)
>>>>>>> c343a4c006950c726f53063bb35300329a16deb2
		{
			if (_envrn[w][ch] == '=')
			{
				lval = _strlen(_envrn[w] + ch + 1);
<<<<<<< HEAD
				add_var_end(ch, i, _envrn[w] + ch + 1, lv`al);
=======
				add_var_end(h, i, _envrn[w] + ch + 1, lval);
>>>>>>> c343a4c006950c726f53063bb35300329a16deb2
				return;
			}

			if (in[i] == _envrn[w][ch])
				i++;
			else
				break;
		}
	}
	for (i = 0; in[i]; i++)
	{
		if (in[i] == ' ' || in[i] == '\t' || in[i] == ';' || in[i] == '\n')
			break;
	}

	add_var_end(ch, i, NULL, 0);
}

/**
 * var_checker - this checks if the typed variable is either $$ or $.
 * @h: the head of the list
 * @in: the input.
 * @st: the status of shell
 * @data: the shell info
 * Return: Non.
 */
int var_checker(r_var **h, char *in, char *st, data_shell *data)
{
	int i, l_st, l_pid;

	l_st = _strlen(st);
	l_pid = _strlen(data->pid);
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				add_var_end(h, 2, st, l_st), i++;
			else if (in[i + 1] == '$')
				add_var_end(h, 2, data->pid, l_pid), i++;
			else if (in[i + 1] == '\n')
				add_var_end(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_var_end(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_var_end(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_var_end(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_var_end(h, 0, NULL, 0);
			else
				env_checker(h, in + i, data);
		}
	}
	return (i);
}

/**
 * var_input -this changes the input string into variables
 * @head: the head of the list
 * @input: the input
 * @new_input: the replaced string
 * @nlen: new length
 * Return: new replaced string
 */
char *var_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *ind;
	int i, g, k;

	ind = *head;
	for (g = i = 0; i < nlen; i++)
	{
		if (input[g] == '$')
		{
			if (!(ind->len_var) && !(ind->len_val))
			{
				new_input[i] = input[g];
				g++;
			}
			else if (ind->len_var && !(ind->len_val))
			{
				for (k = 0; k < ind->len_var; k++)
					g++;
				i--;
			}
			else
			{
				for (k = 0; k < ind->len_val; k++)
				{
					new_input[i] = ind->val[k];
					i++;
				}
				g += (ind->len_var);
				i--;
			}
			ind = ind->next;
		}
		else
		{
			new_input[i] = input[g];
			g++;
		}
	}
	return (new_input);
}

/**
 * replace_var replaced string into vars
 * @input: the input
 * @datash: the shell info
 * Return: replaced string
 */
char *replace_var(char *input, data_shell *datash)
{
	r_var *h, *ind;
	char *st, *n_input;
	int olen, nlen;

	st = aux_itoa(datash->status);
	h = NULL;
	olen = var_checker(&h, input, st, datash);
	if (h == NULL)
	{
		free(st);
		return (input);
	}
	ind = h;
	nlen = 0;
	while (ind != NULL)
	{
		nlen += (ind->len_val - ind->len_var);
		ind = ind->next;
	}
	nlen += olen;
	n_input = malloc(sizeof(char) * (nlen + 1));
	n_input[nlen] = '\0';
	n_input = var_input(&h, input, n_input, nlen);
	free(input);
	free(st);
    var_list_free(&h);
	return (n_input);
}
