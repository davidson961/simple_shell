#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct ShellData - shell struct containing relevant information
 * @av: argument vector.
 * @input: string input from user
 * @cmdArgs: tokens of commands
 * @status: update on status.
 * @commandCounter: current line count.
 * @_environ: environ variable
 * @pid: pid of the shell process.
 */
typedef struct ShellData
{
	char **av;
	char *input;
	char **cmdArgs;
	int status;
	int commandCounter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct SeparatorList - singly-linked-list
 * @separator: separator
 * @next: proceeding node
 * Description: stores separator
 */
typedef struct SeparatorList
{
	char separator;
	struct SeparatorList *next;
} sep_list;

/**
 * struct LineList - singly-linked-list
 * @line: cmd line
 * @next: proceeding node
 * Description: stores cmd line.
 */
typedef struct LineList
{
	char *line;
	struct LineList *next;
} line_list;

/**
 * struct EnvVarList - singly-linked-list
 * @len_var: length of variable
 * @val: value of variable
 * @len_val: length of value
 * @next: proceeding node
 * Description: singly-linked-list to store variables
 */
typedef struct EnvVarList
{
	int len_var;
	char *val;
	int len_val;
	struct EnvVarList *next;
} r_var;

/**
 * struct Builtin - struct containing cmd arguments.
 * @name: abr. for built-in cmd
 * @f: pointer function.
 */
typedef struct Builtin
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

void freeData(data_shell *shellData);
void initData(data_shell *shellData, char **av);

sep_list *addSeparatorEnd(sep_list **head, char sep);
void freeSeparatorList(sep_list **head);
line_list *addLineEnd(line_list **head, char *line);
void freeLineList(line_list **head);

r_var *addVarEnd(r_var **head, int lvar, char *var, int lval);
void freeEnvVarList(r_var **head);

char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocDp(char **ptr, unsigned int old_size, unsigned int new_size);

char *_strdup(const char *s);
int _strlen(const char *s);
int compareChars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

void reverseString(char *s);

int charRepeat(char *input, int i);
int syntaxErrOp(char *input, int i, char last);
int firstChar(char *input, int *i);
void syntaxErrPrinter(data_shell *datash, char *input, int i, int bool);
int syntaxErrChecker(data_shell *datash, char *input);

char *removeComment(char *in);
void shellLoop(data_shell *datash);
char *_readline(int *i_eof);

char *charSwap(char *input, int bool);
void addNodes(sep_list **head_s, line_list **head_l, char *input);
void nextCmdLine(sep_list **list_s, line_list **list_l, data_shell *datash);
int commandSplit(data_shell *datash, char *input);
char **tokenizeLine(char *input);

void envChecker(r_var **h, char *in, data_shell *data);
int varChecker(r_var **h, char *in, char *st, data_shell *data);
char *varInput(r_var **head, char *input, char *new_input, int nlen);
char *replaceVar(char *input, data_shell *datash);

int executeLine(data_shell *datash);

int searchableCurrentDir(char *path, int *i);
char *locateCmd(char *cmd, char **_environ);
int checkExecutable(data_shell *datash);
int checkCmdErr(char *dir, data_shell *datash);
int executeCmd(data_shell *datash);

int compareEnvNames(const char *nenv, const char *name);
char *getEnv(const char *name, char **_environ);
int envPrinter(data_shell *datash);

char *infoCp(char *name, char *value);
void setEnvVar(char *name, char *value, data_shell *datash);
int setEnv(data_shell *datash);
int unsetEnv(data_shell *datash);

void parallelCd(data_shell *datash);
void cdTo(data_shell *datash);
void cdPrevious(data_shell *datash);
void cdHome(data_shell *datash);

int changeDirectory(data_shell *datash);

int (*getBuiltin(char *cmd))(data_shell *datash);

int shellExit(data_shell *datash);

int getLength(int n);
char *convertIntToString(int n);
int convertStrToInt(char *s);

char *cdStrcat(data_shell *, char *, char *, char *);
char *getCdErr(data_shell *datash);
char *notFoundErr(data_shell *datash);
char *exitShellErr(data_shell *datash);

char *errorGetAlias(char **args);
char *envErr(data_shell *datash);
char *errorSyntax(char **args);
char *errorPermission(char **args);
char *pathDeniedErr(data_shell *datash);

int errorGet(data_shell *datash, int eval);

void handleSIGINT(int sig);

void helpEnv(void);
void helpSetEnv(void);
void helpUnsetEnv(void);
void helpGeneral(void);
void helpExit(void);

void help(void);
void helpAlias(void);
void helpCd(void);

int getHelp(data_shell *datash);

#endif
