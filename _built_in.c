#include "main.h"

/**
 * getBuiltin - calls builtin function from command
 * @command: command
 * Return: function pointer to the builtin command
 */
int (*getBuiltin(char *command))(data_shell *)
{
	builtin_t builtins[] = {
		{ "env", envPrinter },
		{ "exit", shellExit },
		{ "setenv", setEnv },
		{ "unsetenv", unsetEnv },
		{ "cd", changeDirectory },
		{ "help", getHelp },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; builtins[i].name; i++)
	{
		if (_strcmp(builtins[i].name, command) == 0)
			break;
	}
	return (builtins[i].f);
}
