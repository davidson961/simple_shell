#include "main.h"

/**
 * parentCd - change to parent directory
 * @datash: shell info
 * Return: Non.
 */
void parentCd(data_shell *datash)
{
	char _pwd[PATH_MAX];
	char *dir, *cpyPwd, *cpyStrtokPwd;

	getcwd(_pwd, sizeof(_pwd));
	cpyPwd = _strdup(_pwd);
	environ_set("OLDPWD", cpyPwd, datash);
	dir = datash->args[1];
	if (_strcmp(".", dir) == 0)
	{
		environ_set("PWD", cpyPwd, datash);
		free(cpyPwd);
		return;
	}
	if (_strcmp("/", cpyPwd) == 0)
	{
		free(cpyPwd);
		return;
	}
	cpyStrtokPwd = cpyPwd;
	revString(cpyStrtokPwd);
	cpyStrtokPwd = _strtok(cpyStrtokPwd, "/");
	if (cpyStrtokPwd != NULL)
	{
		cpyStrtokPwd = _strtok(NULL, "\0");

		if (cpyStrtokPwd != NULL)
			revString(cpyStrtokPwd);
	}
	if (cpyStrtokPwd != NULL)
	{
		chdir(cpyStrtokPwd);
		environ_set("PWD", cpyStrtokPwd, datash);
	}
	else
	{
		chdir("/");
		environ_set("PWD", "/", datash);
	}
	datash->status = 0;
	free(cpyPwd);
}

/**
 * cdTo - change directory
 * @datash: shell info
 * Return: Non
 */
void cdTo(data_shell *datash)
{
	char _pwd[PATH_MAX];
	char *dir, *cpyPwd, *cpyDir;

	getcwd(_pwd, sizeof(_pwd));

	dir = datash->args[1];
	if (chdir(dir) == -1)
	{
		errGet(datash, 2);
		return;
	}
	cpyPwd = _strdup(_pwd);
	environ_set("OLDPWD", cpyPwd, datash);
	cpyDir = _strdup(dir);
	environ_set("PWD", cpyDir, datash);
	free(cpyPwd);
	free(cpyDir);
	datash->status = 0;
	chdir(dir);
}

/**
 * cdPrev - move to previous directory
 * @datash: shell info
 * Return: Non
 */
void cdPrev(data_shell *datash)
{
	char _pwd[PATH_MAX];
	char *pCPwd, *pOldPwd, *cpyPwd, *cpyOldPwd;
	getcwd(_pwd, sizeof(_pwd));
	cpyPwd = _strdup(_pwd);
	pOldPwd = _getenv("OLDPWD", datash->_environ);
	if (pOldPwd == NULL)
		cpyOldPwd = cpyPwd;
	else
		cpyOldPwd = _strdup(pOldPwd);
	environ_set("OLDPWD", cpyPwd, datash);
	if (chdir(cpyOldPwd) == -1)
		environ_set("PWD", cpyPwd, datash);
	else
		environ_set("PWD", cpyOldPwd, datash);
	pCPwd = _getenv("PWD", datash->_environ);
	write(STDOUT_FILENO, pCPwd, _strlen(pCPwd));
	write(STDOUT_FILENO, "\n", 1);
	free(cpyPwd);
	if (pOldPwd)
		free(cpyOldPwd);
	datash->status = 0;
	chdir(pCPwd);
}

/**
 * cdHome - move to home
 * @datash: shell info
 * Return: Non
 */
void cdHome(data_shell *datash)
{
	char *pCPwd, *hom;
	char _pwd[PATH_MAX];

	getcwd(_pwd, sizeof(_pwd));
	pCPwd = _strdup(_pwd);
	hom = _getenv("HOME", datash->_environ);
	if (hom == NULL)
	{
		environ_set("OLDPWD", pCPwd, datash);
		free(pCPwd);
		return;
	}
	if (chdir(hom) == -1)
	{
		errGet(datash, 2);
		free(pCPwd);
		return;
	}
	environ_set("OLDPWD", pCPwd, datash);
	environ_set("PWD", hom, datash);
	free(pCPwd);
	datash->status = 0;
}
