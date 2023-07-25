#include "main.h"

/**
 * freeData - frees data
 * @shellData: shell info
 * Return: None
 */
void freeData(data_shell *shellData)
{
	unsigned int i;

	for (i = 0; shellData->_environ[i]; i++)
		free(shellData->_environ[i]);
	free(shellData->_environ);
	free(shellData->pid);
}

/**
 * initData - Initialize data
 *
 * @shellData: shell info
 * @args: arguments
 * Return: None
 */
void initData(data_shell *shellData, char **args)
{
	unsigned int i;

	shellData->args = args;
	shellData->input = NULL;
	shellData->cmdArgs = NULL;
	shellData->status = 0;
	shellData->counter = 1;
	for (i = 0; environ[i]; i++)
		;
	shellData->_environ = malloc(sizeof(char *) * (i + 1));
	for (i = 0; environ[i]; i++)
	{
		shellData->_environ[i] = _strdup(environ[i]);
	}
	shellData->_environ[i] = NULL;
	shellData->pid = convertIntToString(getpid());
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	data_shell shellData;
	(void) argc;

	signal(SIGINT, handleSIGINT);
	initData(&shellData, argv);
	shellLoop(&shellData);
	freeData(&shellData);
	if (shellData.status < 0)
		return (255);
	return (shellData.status);
}
