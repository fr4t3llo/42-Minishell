/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:44:10 by skasmi            #+#    #+#             */
/*   Updated: 2022/10/22 05:38:22 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <./libc.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define PIPE 1
# define WORD 2
# define RED_IN 3
# define RED_OUT 4
# define APPEND 5
# define HEREDOC 6
# define DBL 6
# define SNGL 7
// global variable ***

typedef struct s_variable
{
	char	*val;
	char	*var;
	int		len;
	char	*to_exp;
	int		i;
}			t_variable;

typedef struct s_env
{
	char				*data;
	char				*value;
	struct s_env		*next;
	struct s_env		*prev;
}						t_env;

typedef struct s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}						t_garbage;

typedef struct s_global_var
{
	t_env				*env;
	t_garbage			*garbage;
	int					status;
	int					doc;
	int					oldpwd;
	int					pwd;
	int					expand;
	int					pid;
}						t_global_var;

t_global_var			g_var;

typedef struct s_token
{
	int					type;
	char				value;
	struct s_token		*next;
}						t_token;

typedef struct s_int
{
	int					i;
	int					j;
	int					k;
	int					nb_for_alloc;
	int					nb_of_line;
}						t_int;

typedef struct s_list
{
	char				*content;
	struct s_list		*next;
}						t_list;

typedef struct s_pipe
{
	char				*cmd;
	struct s_pipe		*next;
}						t_pipe;

typedef struct s_redic
{
	char				*content;
	int					type;
	struct s_redic		*next;
}						t_redic;

typedef struct s_args
{
	char				*arg;
	char				*token;
	struct s_args		*next;
}						t_args;

typedef struct s_lexm
{
	char				*cmd;
	int					type;
	struct s_lexm		*next;
}						t_lexm;

void					add_garbage(void *value);
void					ft_aux_export(char *var, char *val);
char					*ft_extratct_string_from_qutes(char *str);
int						ft_check_pipe(char *cmd);
int						ft_check_red(char *cmd);
void					skip_single_dbl_quote(char *line, int *k);
int						ft_check_cmd_sq_q(char *cmd);
int						ft_check_dbl_pipe(char *cmd);
int						ft_check_redirection(char *cmd);
int						ft_check_redirection_2(char *cmd);
int						ft_skip_before_space(char *cmd);
int						ft_check_semicolon(char *cmd);
int						ft_syntax_general(char *cmd);
int						ft_get_before(char *line, int index);
int						ft_get_after(char *line, int index);
int						ft_check_before_after_symbole(char *cmd);
int						ft_check_single_dbl_qt(char *cmd);
int						ft_complete(char *cmd, int i);
int						ft_check_single_dbl_qt(char *cmd);

// Expend
char					*ft_expand(char *cmd);
char					*get_from_env(char *var);

//libft_funcs
int						ft_isalpha(int c);
char					*ft_itoa(int c);
int						ft_isalnum(int c);
char					*ft_itoa(int n);
char					**ft_split(char const *s, char c);
char					*ft_strcpy(char *dst, const char *src);
int						ft_strcmp(char *s1, char *s2);
int						ft_atoi(const char *str);
int						ft_strchr(const char *s, int c);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strdup(const char *s1);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
void					*ft_memmove(void *str1, const void *str2, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strlen(const char *str);

//list env
t_env					*ft_lstnew_env(char *data, char *value);
void					ft_lst_addback_env(t_env **lst, t_env *new);
t_env					*ft_lstlast_env(t_env *lst);

//minishell function
void					ft_env(void);
char					*ft_execute_bulletin(char *cmd);
void					ft_pwd(char **path);
void					ft_error_cmd(char **cmd);
int						ft_check_change_dir(char *cmd);
void					ft_export(char **cmd);
void					*ft_get_data(char *cmd);
char					*ft_get_value(char *cmd);
void					ft_cd(char **path);
char					*ft_get_home(void);
int						ft_exit(char **cmd);
void					ft_unset(char *cmd);
void					ft_unset_more_then_one(char **ptr);
char					*ft_get_cd(char *cmd);
int						ft_get_cd_without_arg(char *cmd);
void					ft_pipe(char *cmd);
int						ft_bulletin(char *cmd);
void					ft_convert_to_lower(char *cmd);

// list of pipes
void					ft_lstadd_back(t_pipe **lst, char *new);
void					ft_lstadd_front(t_pipe **lst, t_pipe *new);
t_pipe					*ft_lstlast(t_pipe *lst);
t_pipe					*ft_lstnew(char *content);
void					ft_start_exe(t_pipe *lst);
void					ft_execution(char *cmd);
char					**ft_get_env2(void);
void					ft_echo(char **cmd);
void					ft_lstadd_back_red(t_redic **lst, char *new, char c);
void					ft_lstadd_front_red(t_redic **lst, t_redic *new);
t_redic					*ft_lstlast_red(t_redic *lst);
t_redic					*ft_lstnew_red(char *content, char c);

// handle redirection
void					run_rediction(t_redic *lst_of_red);
void					ft_putstr_fd(char *s, int fd);
char					*ft_strstr(char *haystack, char *needle);
char					**args_lst_to_tab(t_pipe *lst_of_args);
void					ft_get_args_and_red(char *cmd, t_pipe **lst_of_args,
							t_redic **lst_of_red);
void					ft_puterror(char *err, char *msg);
void					add_to_lexer(t_lexm **lst, char *content);
int						token(char *cmd);
t_lexm					*new_lexer(char *content);

// norm
void					handle_sig(int pid);
char					*lexter_to_string(t_lexm *lxm);
t_lexm					*ft_lexer(char *cmd);
void					handler(int sig);
int						event(void);
void					ft_change_pwd_and_old(char *ptr, char *cwd);
void					get_status(void);
void					dup_1(int fd[2]);
void					dup_0(int fd[2]);
void					fork_resource(void);
void					sub_main(t_pipe *tmp, int fd[2]);
void					ft_get_args_and_red(char *cmd, t_pipe **lst_of_args,
							t_redic **lst_of_red);

int						size_of_lst(t_pipe *lst_of_args);
char					**args_lst_to_tab(t_pipe *lst_of_args);
void					ft_puterror(char *err, char *msg);
void					errno_err(char *ptr);
void					ft_get_red(char *cmd, int *i, t_redic **lst_of_red);
void					ft_get_args(char *cmd, t_pipe **lst_of_args, int *i);
char					**ft_get_env2(void);
int						inverse_expand(char *cmd, int i, int expand);
char					*lst_expand(char *ret, char *cmd, int *i);
void					set_to_expand(t_lexm **lexer, char **to_expand);
void					ft_lexer_2(int *i, char *cmd, t_lexm **lexer);
char					*ft_lexer_1(int *i, char *cmd, char *to_expand);
char					*lexter_to_string(t_lexm *lxm);
void					handle_sig(int pid);
int						only_space(char *cmd);
int						ft_bulletin(char *cmd);
int						ft_bulletin_2(char **ptr);
void					only_export(void);
void					ft_new_env(char **env);
int						event(void);
void					handler(int sig);
void					main_heredoc(t_lexm **lexer);
int						here_loop(t_lexm *tmp, char *file_name, int fd);
void					ft_error_and_exit(char **ptr);
char					*get_unique_name(void);
void					ft_run_heredoc(t_lexm **lexer);
void					pass_or_not(char *cmd);
char					*check_heredoc(char *cmd);
void					ft_shllvl(void);
int						ft_check_change_dir(char *cmd);
char					*check_heredoc(char *cmd);
// sayfe

void					ft_new_env(char **env);
void					ft_if_path(void);
int						ft_valid_var(char *c);

#endif
