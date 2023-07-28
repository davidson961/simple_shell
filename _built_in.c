#include "main.h"

/**
 * get_built_in - brings forth builtin function from command
 * @cmd: the command
 * Return: the function pointer to the builtin command
 */
int (*get_built_in(char *cmd))(data_shell *)
{
	builtin_t built[] = {
		{ "env", env_printer },
		{ "exit", shell_exit },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", change_dir },
		{ "help", help_get },
		{ NULL, NULL }
	};
	int q;

	for (q = 0; built[q].name; q++)
	{
		if (_strcmp(built[q].name, cmd) == 0)
			break;
	}
	return (built[q].f);
}
