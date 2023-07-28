#include "main.h"

/**
 * charSwap - swaps | and &
 * @input: input
 * @bool: swap type
 * Return: swapped input
 */
char *charSwap(char *input, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[i + 1] != '|')
					input[i] = 16;
				else
					i++;
			}
			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	return (input);
}

/**
 * addNodes - add separators and command in the lists
 * @headS: head of separator list
 * @headL: head of command lines list
 * @input: input
 * Return: Non
 */
void addNodes(sep_list **headS, line_list **headL, char *input)
{
	int i;
	char *linePtr;

	input = charSwap(input, 0);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
			addSepEnd(headS, input[i]);

		if (input[i] == '|' || input[i] == '&')
		{
			addSepEnd(headS, input[i]);
			i++;
		}
	}
	linePtr = _strtok(input, ";|&");
	do{
		linePtr = charSwap(linePtr, 1);
		addLineEnd(headL, linePtr);
		linePtr = _strtok(NULL, ";|&");
	} while (linePtr != NULL);
}

/**
 * nextCmdLine - move to the next command line
 * @listS: separator list
 * @listL: command line list
 * @datash: shell info
 * Return: Non
 */
void nextCmdLine(sep_list **listS, line_list **listL, data_shell *datash)
{
	int lpSep;
	sep_list *lsSep;
	line_list *lsLine;

	lpSep = 1;
	lsSep = *listS;
	lsLine = *listL;

	while (lsSep != NULL && lpSep)
	{
		if (datash->status == 0)
		{
			if (lsSep->separator == '&' || lsSep->separator == ';')
				lpSep = 0;
			if (lsSep->separator == '|')
				lsLine = lsLine->next, lsSep = lsSep->next;
		}
		else
		{
			if (lsSep->separator == '|' || lsSep->separator == ';')
				lpSep = 0;
			if (lsSep->separator == '&')
				lsLine = lsLine->next, lsSep = lsSep->next;
		}
		if (lsSep != NULL && !lpSep)
			lsSep = lsSep->next;
	}
	*listS = lsSep;
	*listL = lsLine;
}

/**
 * commandSplit - splits command lines
 * @datash: shell info
 * @input: input
 * Return: 0 or 1
 */
int commandSplit(data_shell *datash, char *input)
{

	sep_list *headS, *listS;
	line_list *headL, *listL;
	int lp;

	headS = NULL;
	headL = NULL;
	addNodes(&headS, &headL, input);
	listS = headS;
	listL = headL;
	while (listL != NULL)
	{
		datash->input = listL->line;
		datash->cmdArgs = tokenizeLine(datash->input);
		lp = executeLine(datash);
		free(datash->cmdArgs);
		if (lp == 0)
			break;
		nextCmdLine(&listS, &listL, datash);

		if (listL != NULL)
			listL = listL->next;
	}
	sepListFree(&headS);
	lineListFree(&headL);
	if (lp == 0)
		return (0);
	return (1);
}

/**
 * tokenizeLine - tokenize the string
 * @input: input
 * Return: splitted string.
 */
char **tokenizeLine(char *input)
{
	size_t size;
	size_t i;
	char **tokenArr;
	char *token;

	size = TOK_BUFSIZE;
	tokenArr = malloc(sizeof(char *) * (size));
	if (tokenArr == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}
	token = _strtok(input, TOK_DELIM);
	tokenArr[0] = token;
	for (i = 1; token != NULL; i++)
	{
		if (i == size)
		{
			size += TOK_BUFSIZE;
			tokenArr = _reallocdp(tokenArr, i, sizeof(char *) * size);
			if (tokenArr == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokenArr[i] = token;
	}
	return (tokenArr);
}
