#include "main.h"

/**
 * char_repeat - this counts the repetitions of a char
 *
 * @input: the input
 * @i: the index to check
 * Return: numbers of repetitions
 */
int char_repeat(char *input, int i)
{
	if (*(input - 1) == *input)
		return (char_repeat(input - 1, i + 1));

	return (i);
}

/**
 * syntax_err_op this looks for syntax errors
 * @input: the input
 * @i: the index
 * @last: last character that was read
 * Return: the index of the error position or 0
 */
int syntax_err_op(char *input, int i, char last)
{
	int counter;

	counter = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (syntax_err_op(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);
		if (last == '|')
		{
			counter = char_repeat(input, 0);
			if (counter == 0 || counter > 1)
				return (i);
		}
	}
	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);
		if (last == '&')
		{
			counter = char_repeat(input, 0);
			if (counter == 0 || counter > 1)
				return (i);
		}
	}
	return (syntax_err_op(input + 1, i + 1, *input));
}

/**
 * fst_char - this finds index of the first char
 * @input: the input
 * @i: index
 * Return: 1 or 0
 */
int fst_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;
		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);
		break;
	}
	return (0);
}

/**
 * syntax_err_printer - the error message when syntax error is found
 * @datash: the shell info
 * @input: the input
 * @i: the position of error
 * @bool: this controls message error
 * Return: Non
 */
void syntax_err_printer(data_shell *datash, char *input, int i, int bool)
{
	char *message, *message2, *message3, *err, *count;
	int len;

	if (input[i] == ';')
	{
		if (bool == 0)
			message = (input[i + 1] == ';' ? ";;" : ";");
		else
			message = (input[i - 1] == ';' ? ";;" : ";");
	}
	if (input[i] == '|')
		message = (input[i + 1] == '|' ? "||" : "|");
	if (input[i] == '&')
		message = (input[i + 1] == '&' ? "&&" : "&");
	message2 = ": Syntax error: \"";
	message3 = "\" unexpected\n";
	count = aux_itoa(datash->counter);
	len = _strlen(datash->av[0]) + _strlen(count);
	len += _strlen(message) + _strlen(message2) + _strlen(message3) + 2;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(count);
		return;
	}
	_strcpy(err, datash->av[0]);
	_strcat(err, ": ");
	_strcat(err, count);
	_strcat(err, message2);
	_strcat(err, message);
	_strcat(err, message3);
	_strcat(err, "\0");
	write(STDERR_FILENO, err, len);
	free(err);
	free(count);
}

/**
 * syntax_err_checker - this finds and prints syntax error
 * @datash: the shell info
 * @input: the input
 * Return: 1 or 0
 */
int syntax_err_checker(data_shell *datash, char *input)
{
	int start = 0;
	int first_char = 0;
	int i = 0;

	first_char = fst_char(input, &start);
	if (first_char == -1)
	{
		syntax_err_printer(datash, input, start, 0);
		return (1);
	}
	i = syntax_err_op(input + start, 0, *(input + start));
	if (i != 0)
	{
		syntax_err_printer(datash, input, start + i, 1);
		return (1);
	}
	return (0);
}
