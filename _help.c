#include "main.h"

/**
 * _helpEnv - displays information about the 'env' command
 * Return: None
 */
void _helpEnv(void)
{
    char *help = "env: env [option] [name=value] [command [args]]\n\t";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "Print the environment of the shell.\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * _helpSetenv - displays information about the 'setenv' command
 * Return: None
 */
void _helpSetenv(void)
{
    char *help = "setenv: setenv (const char *name, const char *value, int replace)\n\t";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "Add a new definition to the environment\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * _helpUnsetenv - displays information about the 'unsetenv' command
 * Return: None
 */
void _helpUnsetenv(void)
{
    char *help = "unsetenv: unsetenv (const char *name)\n\t";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "Remove an entry completely from the environment\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * _helpGeneral - displays general help information
 * Return: None
 */
void _helpGeneral(void)
{
    char *help = "^-^ bash, version 1.0(1)-release\n";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "These commands are defined internally. Type 'help' to see the list";
    write(STDOUT_FILENO, help, _strlen(help));
    help = "Type 'help name' to find out more about the function 'name'.\n\n ";
    write(STDOUT_FILENO, help, _strlen(help));
    help = " alias: alias [name=['string']]\n  cd: cd [-L|[-P [-e]] [-@]] ";
    write(STDOUT_FILENO, help, _strlen(help));
    help = "[dir]\n  exit: exit [n]\n  env: env [option] [name=value] [command ";
    write(STDOUT_FILENO, help, _strlen(help));
    help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
    write(STDOUT_FILENO, help, _strlen(help));
    help = "unsetenv [variable]\n";
    write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * _helpExit - displays information about the 'exit' command
 * Return: None
 */
void _helpExit(void)
{
    char *help = "exit: exit [n]\n Exit shell.\n";

    write(STDOUT_FILENO, help, _strlen(help));
    help = "Exits the shell with a status of N. If N is omitted, the exit";
    write(STDOUT_FILENO, help, _strlen(help));
    help = "status is that of the last command executed\n";
    write(STDOUT_FILENO, help, _strlen(help));
}
