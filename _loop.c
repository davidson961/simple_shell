#include "main.h"

/**
 * removeComment - Removes comments from the input.
 *
 * @input: Input string containing the command.
 * Return: Input without the comments.
 */
char *removeComment(char *input)
{
    int i, position;

    position = 0;
    for (i = 0; input[i]; i++)
    {
        if (input[i] == '#')
        {
            if (i == 0)
            {
                free(input);
                return (NULL);
            }
            if (input[i - 1] == ' ' || input[i - 1] == '\t' || input[i - 1] == ';')
                position = i;
        }
    }
    if (position != 0)
    {
        input = _realloc(input, i, position + 1);
        input[position] = '\0';
    }
    return (input);
}

/**
 * shellLoop - The shell's main loop.
 * @datash: Shell information.
 * Return: No return.
 */
void shellLoop(data_shell *datash)
{
    int lp, iEof;
    char *input;

    lp = 1;
    while (lp == 1)
    {
        write(STDIN_FILENO, "--> ", 4);
        input = _readline(&iEof);
        if (iEof != -1)
        {
            input = removeComment(input);
            if (input == NULL)
                continue;

            if (syntaxErrChecker(datash, input) == 1)
            {
                datash->status = 2;
                free(input);
                continue;
            }
            input = replaceVar(input, datash);
            lp = commandSplit(datash, input);
            datash->counter += 1;
            free(input);
        }
        else
        {
            lp = 0;
            free(input);
        }
    }
}

/**
 * _readline - Reads input from standard input.
 * @iEof: Return value of getline.
 * Return: Input in the form of a string.
 */
char *_readline(int *iEof)
{
    char *input = NULL;
    size_t size = 0;

    *iEof = getline(&input, &size, stdin);

    return (input);
}
