#include "main.h"

/**
 * helpGet - function to call builtin help
 * @shellData: shell_info
 * Return: Return 1
*/
int helpGet(data_shell *shellData)
{
	if (shellData->cmdArgs[1] == 0)
		_helpGeneral();
	else if (_strcmp(shellData->cmdArgs[1], "setenv") == 0)
		_helpSetEnv();
	else if (_strcmp(shellData->cmdArgs[1], "env") == 0)
		_helpEnv();
	else if (_strcmp(shellData->cmdArgs[1], "unsetenv") == 0)
		_helpUnsetEnv();
	else if (_strcmp(shellData->cmdArgs[1], "help") == 0)
		_help();
	else if (_strcmp(shellData->cmdArgs[1], "exit") == 0)
		_helpExit();
	else if (_strcmp(shellData->cmdArgs[1], "cd") == 0)
		_helpCd();
	else if (_strcmp(shellData->cmdArgs[1], "alias") == 0)
		_helpAlias();
	else
		write(STDERR_FILENO, shellData->cmdArgs[0],
		      _strlen(shellData->cmdArgs[0]));

	shellData->status = 0;
	return (1);
}
