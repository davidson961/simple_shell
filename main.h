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
 * struct data - A shell structure containing relevant information.
 * @av: Argument vector.
 * @input: User-input string.
 * @args: Tokens of commands.
 * @status: Updated status information.
 * @counter: Current line count.
 * @_environ: Environment variables.
 * @pid: Process ID of the shell.
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - A singly-linked list node.
 * @separator: The stored separator value.
 * @next: Pointer to the next node in the list.
 * Description: This structure stores a separator in a singly-linked list.
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - A singly-linked list node.
 * @line: The stored command line.
 * @next: Pointer to the next node in the list.
 * Description: This structure stores a command line in a singly-linked list.
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - A singly-linked list node.
 * @len_var: Length of the variable.
 * @val: Value of the variable.
 * @len_val: Length of the value.
 * @next: Pointer to the next node in the list.
 * Description: This singly-linked list is used to store variables.
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - A structure containing command arguments.
 * @name: Abbreviation for built-in command.
 * @f: Pointer to the corresponding function.
 * Description: This structure holds information about built-in commands.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

void free_dt(data_shell *datash);
void set_dt(data_shell *datash, char **av);

sep_list *add_sep_end(sep_list **head, char sep);
void sep_list_free(sep_list **head);
line_list *add_line_end(line_list **head, char *line);
void line_list_free(line_list **head);

r_var *add_var_end(r_var **head, int lvar, char *var, int lval);
void var_list_free(r_var **head);

char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);

void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

void rev_string(char *s);

int char_repeat(char *input, int n);
int syntax_err_op(char *input, int n, char last);
int fst_char(char *input, int *n);
void syntax_err_printer(data_shell *datash, char *input, int n, int m);
int syntax_err_checker(data_shell *datash, char *input);

char *remove_comment(char *in);
void loop_shell(data_shell *datash);
char *_readline(int *i_eof);

char *char_swap(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void next_cmd_line(sep_list **list_s, line_list **list_l, data_shell *datash);
int command_split(data_shell *datash, char *input);
char **tokenize_line(char *input);

void env_checker(r_var **h, char *in, data_shell *data);
int var_checker(r_var **h, char *in, char *st, data_shell *data);
char *var_input(r_var **head, char *input, char *new_input, int nlen);
char *replace_var(char *input, data_shell *datash);

int execute_line(data_shell *datash);

int searchable_cdir(char *path, int *p);
char *locate_cmd(char *cmd, char **_environ);
int check_executable(data_shell *datash);
int check_cmd_err(char *dir, data_shell *datash);
int exe_cmd(data_shell *datash);

int comp_env_names(const char *nenv, const char *name);
char *_getenv(const char *name, char **_environ);
int env_printer(data_shell *datash);

char *info_cp(char *name, char *value);
void environ_set(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

void par_cd(data_shell *datash);
void cd_to(data_shell *datash);
void cd_prev(data_shell *datash);
void cd_home(data_shell *datash);

int change_dir(data_shell *datash);

int (*get_built_in(char *cmd))(data_shell *datash);

int shell_exit(data_shell *datash);

int get_len(int i);
char *aux_itoa(int i);
int _atoi(char *s);

char *cd_strcat(data_shell *datash, char *msg, char *err, char *str_var);
char *get_cd_err(data_shell *datash);
char *not_found_err(data_shell *datash);
char *exit_shell_err(data_shell *datash);

char *error_get_alias(char **args);
char *env_err(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *path_denied_err(data_shell *datash);

int err_get(data_shell *datash, int eval);

void _sigint(int sig);

void _help_env(void);
void _help_setenv(void);
void _help_unsetenv(void);
void _help_general(void);
void _help_exit(void);

void _help(void);
void _help_alias(void);
void _help_cd(void);

int help_get(data_shell *datash);

#endif
