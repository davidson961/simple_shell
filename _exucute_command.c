#include "main.h"

/**
 * searchableCDir - checks if the current directory is searchable.
 * @path: path to check
 * @i: pointer to the index in the path
 * Return: 1 if the current directory is searchable, 0 otherwise
 */
int searchableCDir(char *path, int *i)
{
    if (path[*i] == ':')
        return 1;
    while (path[*i] != ':' && path[*i])
        *i += 1;
    if (path[*i])
        *i += 1;
    return 0;
}

/**
 * locateCmd - looks for the command in the PATH environment variable
 * @cmd: the command to locate
 * @_environ: environment variable
 * Return: location of the command if found, otherwise NULL
 */
char *locateCmd(char *cmd, char **_environ)
{
    char *_path, *pathPtr, *pathToken, *dir;
    int dirLen, cmdLen, i;
    struct stat st;

    _path = _getenv("PATH", _environ);
    if (_path)
    {
        pathPtr = _strdup(_path);
        cmdLen = _strlen(cmd);
        pathToken = _strtok(pathPtr, ":");
        i = 0;
        while (pathToken != NULL)
        {
            if (searchableCDir(_path, &i))
                if (stat(cmd, &st) == 0)
                    return cmd;
            dirLen = _strlen(pathToken);
            dir = malloc(dirLen + cmdLen + 2);
            _strcpy(dir, pathToken);
            _strcat(dir, "/");
            _strcat(dir, cmd);
            _strcat(dir, "\0");
            if (stat(dir, &st) == 0)
            {
                free(pathPtr);
                return dir;
            }
            free(dir);
            pathToken = _strtok(NULL, ":");
        }
        free(pathPtr);
        if (stat(cmd, &st) == 0)
            return cmd;
        return NULL;
    }
    if (cmd[0] == '/')
        if (stat(cmd, &st) == 0)
            return cmd;
    return NULL;
}

/**
 * checkExecutable - checks if the command is executable
 * @datash: shell info
 * Return: 0 if the command is not executable, otherwise returns the index of the command
 */
int checkExecutable(data_shell *datash)
{
    struct stat st;
    int i;
    char *input;

    input = datash->args[0];
    for (i = 0; input[i]; i++)
    {
        if (input[i] == '.')
        {
            if (input[i + 1] == '.')
                return 0;
            if (input[i + 1] == '/')
                continue;
            else
                break;
        }
        else if (input[i] == '/' && i != 0)
        {
            if (input[i + 1] == '.')
                continue;
            i++;
            break;
        }
        else
            break;
    }
    if (i == 0)
        return 0;
    if (stat(input + i, &st) == 0)
    {
        return i;
    }
    errGet(datash, 127);
    return -1;
}

/**
 * checkCmdErr - verifies if the user has access to the command
 * @dir: destination directory
 * @datash: shell info
 * Return: 1 if the user has access to the command, 0 otherwise
 */
int checkCmdErr(char *dir, data_shell *datash)
{
    if (dir == NULL)
    {
        errGet(datash, 127);
        return 1;
    }
    if (_strcmp(datash->args[0], dir) != 0)
    {
        if (access(dir, X_OK) == -1)
        {
            errGet(datash, 126);
            free(dir);
            return 1;
        }
        free(dir);
    }
    else
    {
        if (access(datash->args[0], X_OK) == -1)
        {
            errGet(datash, 126);
            return 1;
        }
    }
    return 0;
}

/**
 * exeCmd- executes a command
 * @datash: shell info
 * Return: 1 when successful, otherwise returns 1.
 */
int exeCmd(data_shell *datash)
{
    pid_t pid;
    pid_t wpid;
    int state, execute;
    char *dir;
    (void)wpid;

    execute = checkExecutable(datash);
    if (execute == -1)
        return 1;
    if (execute == 0)
    {
        dir = locateCmd(datash->args[0], datash->_environ);
        if (checkCmdErr(dir, datash) == 1)
            return 1;
    }
    pid = fork();
    if (pid == 0)
    {
        if (execute == 0)
            dir = locateCmd(datash->args[0], datash->_environ);
        else
            dir = datash->args[0];
        execve(dir + execute, datash->args, datash->_environ);
    }
    else if (pid < 0)
    {
        perror(datash->av[0]);
        return 1;
    }
    else
    {
        do
        {
            wpid = waitpid(pid, &state, WUNTRACED);
        } while (!WIFEXITED(state) && !WIFSIGNALED(state));
    }

    datash->status = state / 256;
    return 1;
}
