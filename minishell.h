#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"
#include <readline/history.h>
#include <readline/readline.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define PATH 5000
#define SUCCESS 0
#define ERROR 1
#define MAX_INT 2147483647

typedef struct s_token
{
	char *str;
	int type;
	struct s_token *prev;
	struct s_token *next;
}               t_token;

typedef struct s_env
{
	char    *value;
	struct s_env *next;
}               t_env;

typedef struct	s_sig
{
	int				sigint;
	int				sigquit;
	int				exit_status;
	pid_t			pid;
}				t_sig;

typedef struct s_mini
{
	t_token *start;
	t_env   *env;
	t_env   *sec_env;
	int in;
	int out;
	int fdin;
	int fdout;
	int pid;
	int pipin;
	int pipout;
	int dad;
	int charge;
	int last;
	int ret;
	int exit;
	int no_exec;
}               t_mini;

void    parser(t_mini *mini);
char    *ft_quote(char *str, int *i);
// char	*ft_substr(char *s, unsigned int start, int len);
// char	*ft_strjoin(char *s1, char *s2);
// int     ft_strlen(char *string);
// char	*ft_strdup(char *s1);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *str, int fd);
void    *delete_memmory(void *str);
///signals.c
void sigint(int c);
void	sigquit(int c);

///minishell.c
void    ft_close(int fd);
void    update_shell_lvl(t_env *env);
void    init_sig(void);
void    reload_std(t_mini *mini);
int     type_search(t_token *token, int i);

//PARSER//
void parser(t_mini *mini);
int quotation(char *stroke, int m_int);
char *spacesof_lines(char *line);

//shlvl.c
int     get_lvl(char *str);
void	skip_space_nl(const char *str, int *i);
int     not_valid_str(char *str);

/////BUILTINS/////
int     update_old_path(t_env *env);
int     find_env(char *old_path, t_env *env);
char    *name_of_env(char *to, char *from);
void	*free_memo(void *s);

////should be deleted later////
void	ft_lstadd_back_m(t_env **lst, t_env *new1);
t_env	*ft_lstlast_m(t_env *lst);
t_env	*ft_lstnew_m(char *content);

char	*ft_strjoin(char const *s1, char const *s2);

//builtins
void    error(char **strs);

//build/pwd
int pwd(void);

//buil /echo
int ft_echo(char **args);
int num_args(char **args);

///builtins/cd_update_path.c///
int	add_env(char *path, t_env *env);
int ft_cd(char **strs, t_env *env);
///uiltins/export///
int len_struct(t_env *env);
char *str_of_env(t_env *sec_env);
void sort_env(t_env *sec_env);
int ft_export(char **strs, t_env *env, t_env *sec_env);
int	valid_env(char *strs);
int export_error(int err, char *strs);
int ft_export(char **strs, t_env *env, t_env *sec_env);

void    init_env(t_mini *mini, char **env);
void    ft_error(char **strs);
void	close_fd(t_mini *mini);
void    init_fds(t_mini *mini);

///builtins/export2_sort.c//
int len_of_env(char **buff);
void sort_buff(char **buff, int len);
//---------------
int			str_env_len(char **env);
void	sort_env1(char **tab, int env_len);
void	free_buff_n(char **tab);
char		**ft_split(char const *s, char c);
//----------------

///builtins/unset
void free_element(t_mini *mini, t_env *env);
int ft_unset(char **strs, t_mini *mini);
/////env//////

int str_env_length(char **env);
size_t get_env_size(t_env *lst);
char    *env_str(t_env *lst);
void print_new_env(t_env *env);
void    sort(char **arr, int env_length);
int init_sec_env(t_mini *mini, char **env_ar);
int count_str_env(char **env);
int env_validation(char *env);
char *get_env_val(char *param, t_env *env);
char *get_name(char *dest, char *src);
int len_env_value(char *env);
int env_char(int c);
char *env_val1(char *env);
void free_arr2(char **arr);

////shlvl///
void    update_shell_lvl(t_env *env);
void init_mini(t_mini *mini);

extern t_sig g_sig;

#endif